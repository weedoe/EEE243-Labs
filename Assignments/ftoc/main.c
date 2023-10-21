#include <stdio.h>
float ftoc(float num2);
int main() {
    float num2;
    printf("Enter a temperature in F: ");
    scanf("%f", &num2);  // NOLINT(*-err34-c)
    ftoc(num2); //F to C conversion function
}
float ftoc(float num2){
    float num3;
    num3 = (num2 - 32) * 5 / 9;
    printf("%0.2f F is %0.2f C\n", num2, num3);
    return 0;
}