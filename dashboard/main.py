import sys
from PySide6.QtWidgets import QApplication, QLabel

app = QApplication(sys.argv)

label = QLabel("Virtual Automotive ECU")
label.resize(400, 100)
label.show()

app.exec()