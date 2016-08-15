#include <stdio.h>
#include <stdint.h>
#include <climits>

int main(int argc, const char* argv[])
{
	char buffer[64];
	size_t len;
	len = snprintf(buffer, sizeof(buffer), "%llu", UINT64_MAX);
	printf("MAX UIN64=%llu(len=%d)¥n",  UINT64_MAX, (int)len);
	len = snprintf(buffer, sizeof(buffer), "%lld", INT64_MAX);
	printf("MAX IN64=%lld(len=%d)¥n",  INT64_MAX, (int) len);
	len = snprintf(buffer, sizeof(buffer), "%lld", INT64_MIN);
	printf("MIN IN64=%lld(len=%d)¥r¥n",  INT64_MIN, (int)len);
	return 0;
}
