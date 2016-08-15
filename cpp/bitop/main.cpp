#include <stdio.h>
#include <stdint.h>

void print_bit(uint32_t val)
{
	printf("HEX: %08x BIN:", val);
	for(uint32_t bit = (1 << (sizeof(uint32_t) * 8 - 1));
		bit != 0 ; bit >>= 1)
	{
		if(val & bit)
		{
			putchar('1');
		} else {
			putchar('0');
		}
	}
	printf("\n");
}

int main(int argc, const char* argv[])
{
	uint32_t vals [] =
		{
			0x0,
			0x1,
			0x2,
			0x4,
			0x8,
			0xffffffff,
		};
	uint32_t mask1 = 0x01;
	uint32_t mask2 = 0x02;	
	
	for(const auto& v: vals)
	{
		uint32_t m = v;
		m &= ~mask2;
		print_bit(m);		
	}

	return 0;
}
