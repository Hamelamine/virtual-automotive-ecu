import sys
import socket
import threading

from PySide6.QtWidgets import (
    QApplication,
    QWidget,
    QLabel,
    QVBoxLayout,
    QHBoxLayout,
    QTableWidget,
    QTableWidgetItem
)

from PySide6.QtCore import Signal, QObject


# ==========================
# TCP Receiver
# ==========================

class ECUReceiver(QObject):

    data_received = Signal(int, int, int)

    def __init__(self):
        super().__init__()

        self.running = True

    def connect_ecu(self):

        HOST = "127.0.0.1"
        PORT = 5000

        self.socket = socket.socket(
            socket.AF_INET,
            socket.SOCK_STREAM
        )

        self.socket.connect(
            (HOST, PORT)
        )

        print("Connected to ECU")

        thread = threading.Thread(
            target=self.receive_loop,
            daemon=True
        )

        thread.start()


    def receive_loop(self):

        while self.running:

            data = self.socket.recv(1024)

            if not data:
                break

            messages = data.decode().split("\n")

            for msg in messages:

                if msg:

                    try:

                        temp, fan, fault = map(
                            int,
                            msg.split(",")
                        )

                        self.data_received.emit(
                            temp,
                            fan,
                            fault
                        )

                    except:
                        pass



# ==========================
# Dashboard
# ==========================

class Dashboard(QWidget):

    def __init__(self):

        super().__init__()

        self.setWindowTitle(
            "Virtual Automotive ECU Dashboard"
        )

        self.resize(
            800,
            500
        )


        self.receiver = ECUReceiver()


        # Labels

        self.temperature_label = QLabel(
            "Temperature: -- °C"
        )

        self.fan_label = QLabel(
            "Fan Speed: -- %"
        )

        self.fault_label = QLabel(
            "Fault: --"
        )


        for label in [
            self.temperature_label,
            self.fan_label,
            self.fault_label
        ]:

            label.setStyleSheet(
                "font-size:18px;"
            )


        # CAN Table

        self.table = QTableWidget(
            0,
            3
        )

        self.table.setHorizontalHeaderLabels(
            [
                "ID",
                "DLC",
                "DATA"
            ]
        )


        # Layout

        top = QHBoxLayout()

        top.addWidget(
            self.temperature_label
        )

        top.addWidget(
            self.fan_label
        )

        top.addWidget(
            self.fault_label
        )


        layout = QVBoxLayout()

        layout.addLayout(top)

        layout.addWidget(
            self.table
        )


        self.setLayout(layout)


        # Connect signals

        self.receiver.data_received.connect(
            self.update_dashboard
        )


        self.receiver.connect_ecu()



    def update_dashboard(
            self,
            temp,
            fan,
            fault
    ):

        self.temperature_label.setText(
            f"Temperature: {temp} °C"
        )


        self.fan_label.setText(
            f"Fan Speed: {fan} %"
        )


        if fault:

            self.fault_label.setText(
                "Fault: OVERTEMPERATURE"
            )

        else:

            self.fault_label.setText(
                "Fault: NONE"
            )


        # Add CAN frame

        row = self.table.rowCount()

        self.table.insertRow(row)


        self.table.setItem(
            row,
            0,
            QTableWidgetItem("0x100")
        )

        self.table.setItem(
            row,
            1,
            QTableWidgetItem("3")
        )

        self.table.setItem(
            row,
            2,
            QTableWidgetItem(
                f"{temp:02X} {fan:02X} {fault:02X}"
            )
        )


        self.table.scrollToBottom()



# ==========================
# Main
# ==========================

if __name__ == "__main__":

    app = QApplication(sys.argv)

    window = Dashboard()

    window.show()

    sys.exit(
        app.exec()
    )