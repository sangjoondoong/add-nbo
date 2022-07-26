#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

int main (int argc, char* argv[])
{
    FILE *fihun, *thou;
    fihun = fopen(argv[1], "rb");
    thou = fopen(argv[2], "rb");

    uint8_t element1[4];
    uint8_t element2[4];

    fread(element1, sizeof(char), 4, fihun);
    fread(element2, sizeof(char), 4, thou);

    uint32_t* p1=reinterpret_cast<uint32_t*>(element1);
    uint32_t* p2=reinterpret_cast<uint32_t*>(element2);

    uint32_t num1=(ntohl(*p1));
    uint32_t num2=(ntohl(*p2));

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1,num1,num2,num2,num1+num2,num1+num2);

    fclose(fihun);
    fclose(thou);
}
