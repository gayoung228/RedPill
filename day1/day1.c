#include <stdio.h>
#include <stdint.h>

// 특정 비트를 1로 변경
#define BIT_SET(var, pos)    ((var) |= (1UL << (pos)))

// 특정 비트를 0으로 변경
#define BIT_CLEAR(var, pos)  ((var) &= ~(1UL << (pos)))

// 특정 비트를 반전
#define BIT_TOGGLE(var, pos) ((var) ^= (1UL << (pos)))

// 특정 비트 확인
#define BIT_CHECK(var, pos)  (!!((var) & (1UL << (pos))))

void print_binary(uint32_t num);

int main(void)
{
    uint32_t data = 0x12345678;  

    printf("=== Day 1: Bitwise Macro Test ===\n");
    printf("[Init]   Hex: 0x%08X | Bin: ", data); 
    print_binary(data); // 2진수로 변환 -> 0001 0010 0011 0100 0101 0110 0111 1000
    printf("\n\n");


    // SET Bit 0 -> 0번째 비트 1로 변경
    printf("[SET]    Target: Bit 0\n");
    BIT_SET(data, 0);  // (0x12345678) |= (1<<0) -> 0001 0010 0011 0100 0101 0110 0111 1001
    printf("Result   Hex: 0x%08X | Bin: ", data);
    print_binary(data);
    printf("\n\n");


    // CLEAR Bit 4 -> 4번째 비트를 0으로 변경
    printf("[CLEAR]  Target: Bit 4\n");
    BIT_CLEAR(data, 4);  // (0x12345678) &= ~(1<<3) -> 0001 0010 0011 0100 0101 0110 0110 1001
    printf("Result   Hex: 0x%08X | Bin: ", data);
    print_binary(data);
    printf("\n\n");

    // TOGGLE Bit 3 -> 3번째 비트 반전
    printf("[TOGGLE] Target: Bit 3\n");
    BIT_TOGGLE(data, 3);  // (0x12345678) ^= ~(1<<2) -> 0001 0010 0011 0100 0101 0110 0110 0001
    printf("Result   Hex: 0x%08X | Bin: ", data);
    print_binary(data);
    printf("\n\n");


    // CHECK Bit 3 -> 3번째 비트 확인
    printf("[CHECK]  Bit 3 is currently: %d\n",
           BIT_CHECK(data, 3));  // (0x12345678) & ~(1<<2) -> 0

    return 0;
}

// 32비트 이진수 출력 함수
void print_binary(uint32_t num)
{
    // i번 비트를 맨 오른쪽(0번 자리)으로 옮긴 뒤, & 1로 해당 비트만 추출한다.
    // i를 31부터 0까지 바꾸며 출력하면 32비트 이진수로 표시된다.
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1); 

        // 4비트마다 띄어쓰기
        if (i % 4 == 0)
            printf(" ");
    }
}
