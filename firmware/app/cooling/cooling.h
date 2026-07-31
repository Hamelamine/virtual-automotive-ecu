#ifndef COOLING_H 
#define COOLING_H 
void Cooling_Init(void); 
void Cooling_Update(int temperature); 
int Cooling_IsFanOn(void); 
#endif /* COOLING_H */