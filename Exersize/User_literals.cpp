#include <iostream>

using namespace std;
//Использование пользовательских литералов для перевода в градусы Кельвина
struct Temperature
{
   double Kelvin;
   Temperature(long double kelvin) : Kelvin(kelvin) {}
};

 Temperature operator"" _C(long double celcius)
 {
 return Temperature(celcius + 273);
 }

Temperature operator "" _F(long double fahrenheit)
 {
 return Temperature((fahrenheit + 459.67) * 5 / 9 ) ;
 }

 int main()
 {
 Temperature kl = 31.73_F;
 Temperature k2 = 0.0_C;

 cout << "kl = " << kl.Kelvin << " K" << endl;
 cout << "k2 = "<< k2.Kelvin << " K" << endl;

 return 0;
 }
