
#define _CRT_NO_SECURE_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#if _MSC_VER > 1200
# define long_long_IS_SUPPORTED_
#endif

int main()
{
	char	buf[21];

	signed __int64		si64	=	0x8765432187654321;
	unsigned __int64	ui64	=	0x8765432187654321;
#ifdef long_long_IS_SUPPORTED_
	signed long long	sll		=	0x8765432187654321;
	unsigned long long	ull		=	0x8765432187654321;
#endif /* long_long_IS_SUPPORTED_ */

	puts("");

	printf("_MSC_VER=%d\n", _MSC_VER);
#ifdef _MSC_FULL_VER
	printf("_MSC_FULL_VER=%d\n", _MSC_FULL_VER);
#endif

	puts("I64:");
	printf(" %%I64d : %I64d\n", si64);
	printf(" %%I64u : %I64u\n", ui64);
	wsprintfA(buf, "%I64d", si64);
	printf("w%%I64d : %s\n", buf);
	wsprintfA(buf, "%I64u", ui64);
	printf("w%%I64u : %s\n", buf);
	printf(" %%lld  : %lld\n", si64);
	printf(" %%llu  : %llu\n", ui64);
	wsprintfA(buf, "%lld", si64);
	printf("w%%lld : %s\n", buf);
	wsprintfA(buf, "%llu", ui64);
	printf("w%%llu : %s\n", buf);

#ifdef long_long_IS_SUPPORTED_
	puts("ll:");
	printf(" %%I64d : %I64d\n", sll);
	printf(" %%I64u : %I64u\n", ull);
	printf(" %%lld  : %lld\n", sll);
	printf(" %%llu  : %llu\n", ull);
#endif /* long_long_IS_SUPPORTED_ */

	return EXIT_SUCCESS;
}

#pragma comment(lib, "user32.lib")

