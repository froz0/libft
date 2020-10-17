/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:24:41 by tmatis            #+#    #+#             */
/*   Updated: 2020/10/17 18:33:18 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "libft.h"

int		g_error = 0;
int		g_success = 0;
int		g_testset_e;
int		g_testset_s;

void	write_result(int index, int success, char *purpose)
{
	printf("\033[0mtest %i: ", index);
	if (success)
	{
		printf("\033[0;32m[OK]");
		g_testset_s++;
	}
	else
	{
		printf("\033[0;31m[KO]");
		g_testset_e++;
	}
	if (purpose)
		printf("\033[0m (%s)", purpose);
	printf("\n");
}



void	test_begin(char *name, char *desc)
{
	g_testset_e = 0;
	g_testset_s = 0;
	printf("\033[1;36m===> %s <===\n", name);
	printf("\033[1;35m%s\n\n", desc);
}

void	test_end(void)
{
	char buffer[5];
	printf("\n");
	if (g_testset_s < g_testset_e + g_testset_s)
	{
		printf("\033[0;31m%i/%i: KO 🥺", g_testset_s , g_testset_s + g_testset_e);
		printf("\n\033[0mPress enter to continue");
		fflush(stdout);
		read(0, buffer, sizeof(buffer));
	}
	else
		printf("\033[0;32m%i/%i: OK 🥳", g_testset_s , g_testset_s + g_testset_e);
	g_error += g_testset_e;
	g_success += g_testset_s;
	printf("\n\n");
}

void	memcpy_testset(void)
{
	char str1[6] = "hello";
	char str2[11] = "hello world";
	char str3[50] = "hello\xf6world😄";
	char ft_dst1[20];
	char ft_dst2[20];
	char ft_dst3[50];
	char dst1[20];
	char dst2[20];
	char dst3[50];

	test_begin("memcpy", "copy n byte of memory");
	write_result(1, memcmp(memcpy(dst1, str1, 6), ft_memcpy(ft_dst1, str1, 6), 6) == 0, NULL);
	write_result(2, memcmp(memcpy(dst2, str2, 10), ft_memcpy(ft_dst2, str2, 10), 10) == 0, NULL);
	write_result(3, memcmp(memcpy(dst3, str3, 15), ft_memcpy(ft_dst3, str3, 15), 15) == 0, NULL);
	test_end();
}

void	memccpy_testset(void)
{
	char dst1[50] = "this text will be overwrited XD";
	char ft_dst1[50] = "this text will be overwrited XD";
	char dst2[50] = "this text will be overwrited XD";
	char ft_dst2[50] = "this text will be overwrited XD";
	char dst3[50] = "this text will be overwrited XD";
	char ft_dst3[50] = "this text will be overwrited XD";
	char dst4[50] = "this text will be overwrited XD";
	char ft_dst4[50] = "this text will be overwrited XD";

	test_begin("memccpy", "copy string until character found");
	write_result(1, memcmp(memccpy(dst1, "lorem ipsum dolor sit", 'i', 21),
					ft_memccpy(ft_dst1, "lorem ipsum dolor sit", 'i', 21), 32) == 0, NULL);
	write_result(2, memcmp(memccpy(dst2, "lorem ipsum dolor sit", 'l', 21),
					ft_memccpy(ft_dst2, "lorem ipsum dolor sit", 'l', 21), 32) == 0, NULL);
	write_result(3, memcmp(memccpy(dst3, "lorem ipsum dolor sit", 'd', 21),
					ft_memccpy(ft_dst3, "lorem ipsum dolor sit", 'd', 21), 32) == 0, NULL);
	write_result(4, memccpy(dst3, "yollloooo", 'd', 10) ==
					ft_memccpy(ft_dst3, "yollloooo", 'd', 10), NULL);
	write_result(5, memcmp(dst3, ft_dst3, 32) == 0, NULL);
	test_end();
}

void	strdup_testset(void)
{
	char str1[] = "hello";
	char str2[] = "hello world";
	char str3[] = "\0  hello";
	char *tofree1;
	char *tofree2;

	test_begin("strdup", "save a copy of a string");
	write_result(1, strcmp(tofree1 = strdup(str1), tofree2 = ft_strdup(str1)) == 0, "Test with \"hello\"");
	free(tofree1);
	free(tofree2);
	write_result(2, strcmp(tofree1 = strdup(str2), tofree2 = ft_strdup(str2)) == 0, "Test with \"hello world\"");
	free(tofree1);
	free(tofree2);
	write_result(3, strcmp(tofree1 = strdup(str3), tofree2 = ft_strdup(str3)) == 0, "Test with \"0 hello\"");
	free(tofree1);
	free(tofree2);
	test_end();
}

void	calloc_testset(void)
{
	void *tofree1;
	void *tofree2;
	test_begin("calloc", "memory allocation");
	write_result(1, memcmp(tofree1 = calloc(10, sizeof(char)), tofree2 = ft_calloc(10, sizeof(char)), 10) == 0,  NULL);
	write_result(2, memcmp(tofree1 = calloc(10, sizeof(int)), tofree2 = ft_calloc(10, sizeof(int)), 10) == 0,  NULL);
	write_result(3, memcmp(tofree1 = calloc(1, sizeof(int)), tofree2 = ft_calloc(1, sizeof(int)), 1) == 0,  NULL);
	write_result(4, memcmp(tofree1 = calloc(0, sizeof(int)), tofree2 = ft_calloc(0, sizeof(int)), 1) == 0,  NULL);
	write_result(5, memcmp(tofree1 = calloc(4, 0), tofree2 = ft_calloc(4, 0), 1) == 0,  NULL);
	free(tofree1);
	free(tofree2);
	test_end();
}

void	strlen_testset(void)
{
	char str1[] = "hello";
	char str2[] = "hello world";
	char str3[] = "";

	test_begin("strlen", "find length of string");
	write_result(1, ft_strlen(str1) == strlen(str1), "Test with \"hello\"");
	write_result(2, ft_strlen(str2) == strlen(str2), "Test with \"hello world\"");
	write_result(3, ft_strlen(str3) == strlen(str3), "Test with \"\"");
	test_end();
}


void	strlcat_testset(void)
{
	char str1[50] = "hello";
	char str2[50] = "hello world";
	char str3[50] = "\0  hello";
	char ft_str1[50] = "hello";
	char ft_str2[50] = "hello world";
	char ft_str3[50] = "\0  hello";
	char str1_2[] = "you";
	char str2_2[] = "hahaha";
	char str3_2[] = "hello";
	test_begin("strlcat", "safe strncat");
	write_result(1, strlcat(str1, str1_2, 4) == ft_strlcat(ft_str1, str1_2, 4), NULL);
	write_result(2, strcmp(str1,ft_str1) == 0, NULL);
	write_result(3, strlcat(str2, str2_2, 5) == ft_strlcat(ft_str2, str2_2, 5), NULL);
	write_result(4, strcmp(str2, ft_str2) == 0, NULL);
	write_result(5, strlcat(str3, str3_2, 10) == ft_strlcat(ft_str3, str3_2, 10), NULL);
	write_result(6, strcmp(str3, ft_str3) == 0, NULL);
	test_end();
}

void	strlcpy_testset(void)
{
	char str1[50] = "hello";
	char str2[50] = "hello world";
	char str3[50] = "\0  hello";
	char ft_str1[50] = "hello";
	char ft_str2[50] = "hello world";
	char ft_str3[50] = "\0  hello";
	char str1_2[] = "you";
	char str2_2[] = "hahaha";
	char str3_2[] = "hello";
	test_begin("strlcpy", "safe strncpy");
	write_result(1, strlcpy(str1, str1_2, 4) == ft_strlcpy(ft_str1, str1_2, 4), NULL);
	write_result(2, strcmp(str1,ft_str1) == 0, NULL);
	write_result(3, strlcpy(str2, str2_2, 5) == ft_strlcpy(ft_str2, str2_2, 5), NULL);
	write_result(4, strcmp(str2, ft_str2) == 0, NULL);
	write_result(5, strlcpy(str3, str3_2, 10) == ft_strlcpy(ft_str3, str3_2, 10), NULL);
	write_result(6, strcmp(str3, ft_str3) == 0, NULL);
	test_end();
}

void	strchr_testset(void)
{
	char str1[50] = "hello";
	char str2[50] = "hello world";
	test_begin("strchr", "locate character in string");
	write_result(1, strchr(str1, 'l') == ft_strchr(str1, 'l'), NULL);
	write_result(2, strchr(str1, '\0') == ft_strchr(str1, '\0'), NULL);
	write_result(3, strchr(str2, 'd') == ft_strchr(str2, 'd'), NULL);
	write_result(4, strchr(str2, 'h') == ft_strchr(str2, 'h'), NULL);
	write_result(5, strchr(str2, 'x') == ft_strchr(str2, 'x'), NULL);
	test_end();
}

void	strrchr_testset(void)
{
	char str1[50] = "hello";
	char str2[50] = "hello world";
	test_begin("strrchr", "locate character in string (last) ");
	write_result(1, strrchr(str1, 'l') == ft_strrchr(str1, 'l'), NULL);
	write_result(2, strrchr(str1, '\0') == ft_strrchr(str1, '\0'), NULL);
	write_result(3, strrchr(str2, 'd') == ft_strrchr(str2, 'd'), NULL);
	write_result(4, strrchr(str2, 'h') == ft_strrchr(str2, 'h'), NULL);
	write_result(5, strrchr(str2, 'x') == ft_strrchr(str2, 'x'), NULL);
	test_end();
}

void	strnstr_testset(void)
{
	char *h1 = "bonjour a tous les amis";
	char *n1 = "a tous";
	char *h2 = "bonjour a tous";
	char *n2 = "la zone";
	char *h3 = "bonjour toi !";
	char *n3 = "";
	char *h4 = "";
	char *n4 = "oauiiiiis";
	char *h5 = "yo la zonla zone";
	char *n5 = "la zone";
	char *h6 = "bonjour a tous les amis";
	char *n6 = "les amis";
	char *h7 = "bonjour a tous les amis";
	char *n7 = "les amis";
	char *h8 = "lorem ipsum dolor sit amet";
	char *n8 = "dolor";
	test_begin("strnstr", "locate a substring in a string with n limit");
	write_result(1, strnstr(h1, n1, 25) == ft_strnstr(h1, n1, 25), NULL);
	write_result(2, strnstr(h2, n2, 15) == ft_strnstr(h2, n2, 15), NULL);
	write_result(3, strnstr(h3, n3, 14) == ft_strnstr(h3, n3, 14), NULL);
	write_result(4, strnstr(h3, n3, 1) == ft_strnstr(h3, n3, 1), NULL);
	write_result(5, strnstr(h3, n3, 0) == ft_strnstr(h3, n3, 0), NULL);
	write_result(6, strnstr(h3, n3, 20) == ft_strnstr(h3, n3, 20), NULL);
	write_result(7, strnstr(h4, n4, 20) == ft_strnstr(h4, n4, 20), NULL);
	write_result(8, strnstr(h5, n5, 50) == ft_strnstr(h5, n5, 50), NULL);
	write_result(9, strnstr(h5, n5, 3) == ft_strnstr(h5, n5, 3), NULL);
	write_result(10, strnstr(h5, n5, 0) == ft_strnstr(h5, n5, 0), NULL);
	write_result(11, strnstr(h6, n6, 3) == ft_strnstr(h6, n6, 3), NULL);
	write_result(12, strnstr(h6, n6, 0) == ft_strnstr(h6, n6, 0), NULL);
	write_result(13, strnstr(h6, n6, 2) == ft_strnstr(h6, n6, 2), NULL);
	write_result(14, strnstr(h7, n7, 30) == ft_strnstr(h7, n7, 30), NULL);
	write_result(15 , strnstr(h8, n8, 15) == ft_strnstr(h8, n8, 15), NULL);
	test_end();
}

void	strncmp_testset(void)
{
	test_begin("strncmp", "compare strings");
	write_result(1, strncmp("salut la zone", "salut la zone", 50) == ft_strncmp("salut la zone", "salut la zone", 50), NULL);
	write_result(2, strncmp("salut la zona", "salut la zona", 50) == ft_strncmp("salut la zona", "salut la zona", 50), NULL);
	write_result(3, strncmp("salut la zon", "salut la zone", 50) == ft_strncmp("salut la zon", "salut la zone", 50), NULL);
	write_result(4, strncmp("salut la zone", "salut la zon", 50) == ft_strncmp("salut la zone", "salut la zon", 50), NULL);
	write_result(5, strncmp("", "", 50) == ft_strncmp("", "", 50), NULL);
	write_result(6, strncmp("aalut la zone", "salut la zone", 50) == ft_strncmp("aalut la zone", "salut la zone", 50), NULL);
	write_result(7, strncmp("salut\0 lq zone", "salut\0 la zone", 50) == ft_strncmp("salut\0 lq zone", "salut\0 la zone", 50), NULL);
	write_result(8, strncmp("salut la zone", "wouugdpoiwhdohf", 50) == ft_strncmp("salut la zone", "wouugdpoiwhdohf", 50), NULL);
	write_result(9, strncmp("salut la zone", "wouugdpoiwhdohf", 10) == ft_strncmp("salut la zone", "wouugdpoiwhdohf", 10), NULL);
	write_result(10, strncmp("salut la zone", "wouugdpoiwhdohf", 0) == ft_strncmp("salut la zone", "wouugdpoiwhdohf", 0), NULL);
	write_result(11, strncmp("salut la zone", "wouugdpoiwhdohf", 1) == ft_strncmp("salut la zone", "wouugdpoiwhdohf", 1), NULL);
	write_result(12, strncmp("salut la zone", "salut wouugdpoiwhdohf", 5) == ft_strncmp("salut la zone", "salut wouugdpoiwhdohf", 5), NULL);
	write_result(13, strncmp("salut la zone", "salut wouugdpoiwhdohf", 4) == ft_strncmp("salut la zone", "salut wouugdpoiwhdohf", 4), NULL);
	write_result(14, strncmp("salut la zone", "salut wouugdpoiwhdohf", 6) == ft_strncmp("salut la zone", "salut wouugdpoiwhdohf", 6), NULL);
	test_end();
}

void	isalpha_testset(void)
{
	test_begin("isalpha", "alphabetic character test");
	write_result(1, isalpha(101) == ft_isalpha(101), NULL);
	write_result(2, isalpha(-101) == ft_isalpha(-101), NULL);
	write_result(3, isalpha(0) == ft_isalpha(0), NULL);
	write_result(4, isalpha(172) == ft_isalpha(172), NULL);
	write_result(5, isalpha(173) == ft_isalpha(173), NULL);
	write_result(6, isalpha('Z') == ft_isalpha('Z'), NULL);
	write_result(7, isalpha('a') == ft_isalpha('a'), NULL);
	write_result(8, isalpha('b') == ft_isalpha('b'), NULL);
	write_result(9, isalpha('g') == ft_isalpha('g'), NULL);
	test_end();
}

void	isnum_testset(void)
{
	test_begin("isnum", "numeric character test");
	write_result(1, isdigit('a') == ft_isdigit('a'), NULL);
	write_result(1, isdigit('0') == ft_isdigit('0'), NULL);
	write_result(1, isdigit('9') == ft_isdigit('9'), NULL);
	write_result(1, isdigit('5') == ft_isdigit('5'), NULL);
	test_end();
}

void	isalnum_testset(void)
{
	test_begin("isalnum", "alphanum char test");
	write_result(1, isalnum('a') == ft_isalnum('a'), NULL);
	write_result(2, isalnum('A') == ft_isalnum('A'), NULL);
	write_result(3, isalnum('z') == ft_isalnum('z'), NULL);
	write_result(4, isalnum('Z') == ft_isalnum('Z'), NULL);
	write_result(5, isalnum('0') == ft_isalnum('0'), NULL);
	write_result(6, isalnum('9') == ft_isalnum('9'), NULL);
	write_result(7, isalnum('@') == ft_isalnum('@'), NULL);
	test_end();
}

void	isascii_testset(void)
{
	test_begin("isascii", "check if ascii");
	write_result(1, isascii('a') == ft_isascii('a'), NULL);
	write_result(2, isascii('A') == ft_isascii('A'), NULL);
	write_result(3, isascii(0) == ft_isascii(0), NULL);
	write_result(4, isascii(127) == ft_isascii(127), NULL);
	write_result(5, isascii(128) == ft_isascii(128), NULL);
	write_result(6, isascii(-65) == ft_isascii(-65), NULL);
	test_end();
}

void	isprint_testset(void)
{
	test_begin("isprint", "check if printable");
	write_result(1, isprint(' ') == ft_isprint(' '), NULL);
	write_result(2, isprint('~') == ft_isprint('~'), NULL);
	write_result(3, isprint('5') == ft_isprint('5'), NULL);
	write_result(4, isprint('<') == ft_isprint('<'), NULL);
	write_result(5, isprint('\n') == ft_isprint('\n'), NULL);
	write_result(6, isprint('\t') == ft_isprint('\t'), NULL);
	test_end();
}

void	toupper_testset(void)
{
	test_begin("toupper", "lower case to upper case letter conversion");
	write_result(1, toupper('a') == ft_toupper('a'), NULL);
	write_result(1, toupper('g') == ft_toupper('g'), NULL);
	write_result(2, toupper('A') == ft_toupper('A'), NULL);
	write_result(3, toupper(150) == ft_toupper(150), NULL);
	write_result(4, toupper(-97) == ft_toupper(-97), NULL);
	test_end();
}

void	tolower_testset(void)
{
	test_begin("tolower", "upper case to lower case letter conversion");
	write_result(1, toupper('A') == ft_toupper('A'), NULL);
	write_result(1, toupper('G') == ft_toupper('G'), NULL);
	write_result(2, toupper('a') == ft_toupper('a'), NULL);
	write_result(3, toupper(150) == ft_toupper(150), NULL);
	write_result(4, toupper(-65) == ft_toupper(-65), NULL);
	test_end();
}

void	memset_testset(void)
{
	char	b1[50];
	char	ft_b1[50];
	char	b2[50];
	char	ft_b2[50];
	test_begin("memset", "fill a byte string with a byte value");
	write_result(1, memcmp(memset(b1 , 'a', 50),ft_memset(ft_b1 , 'a', 50), 40) == 0, NULL);
	write_result(2, memcmp(memset(b1 , -35, 50),ft_memset(ft_b1 , -35, 50), 50) == 0, NULL);
	write_result(3, memcmp(memset(b1 , ';', 10),ft_memset(ft_b1 , ';', 10), 10) == 0, NULL);
	test_end();
}

void	bzero_testset(void)
{
	char str1[12] = "zumba cafew";
	char ft_str1[12] = "zumba cafew";
	char	b1[50];
	char	ft_b1[50];
	char	b2[50];
	char	ft_b2[50];
	test_begin("bzero","write zeroes to a byte string");
	bzero(str1, (0));
	ft_bzero(ft_str1, 0);
	bzero(b1, 50);
	ft_bzero(ft_b1, 50);
	bzero(b2, 20);
	ft_bzero(ft_b2, 20);
	write_result(1, memcmp(str1, ft_str1, 12) == 0, NULL);
	write_result(2, memcmp(b1, ft_b1, 50) == 0, NULL);
	write_result(3, memcmp(b2, ft_b2, 20) == 0, NULL);
	test_end();
}

void	memmove_testset(void)
{
	char dst0[50];
	char ft_dst0[50];
	char str0[16] = "bonjour la zone";
	char str1[16] = "bonjour la zone";
	char dst1[50];
	char ft_dst1[50];
	char dst2[50] = "test avec les overflooooooowwwwwwv";
	char ft_dst2[50] = "test avec les overflooooooowwwwwwv";

	test_begin("memmove", "copy byte string");
	write_result(1, memcmp(memmove(dst0, str0, 16), ft_memmove(ft_dst0, str0, 16) ,16) == 0, NULL);
	write_result(2, memcmp(memmove(dst1, str1, 16), ft_memmove(ft_dst1, str1, 16) ,16) == 0, NULL);
	write_result(3, memcmp(memmove(dst2 + 5, dst2, 16), ft_memmove(ft_dst2 + 5, ft_dst2, 16), 34) == 0, NULL);
	write_result(4, memcmp(memmove(dst2 + 5, dst2 + 8, 16), ft_memmove(ft_dst2 + 5, ft_dst2 + 8, 16), 34) == 0, NULL);
	write_result(5, memcmp(memmove(dst2, dst2, 16), ft_memmove(ft_dst2, ft_dst2, 16), 16) == 0, NULL);
	write_result(6, memcmp(memmove(dst2+10, dst2+2, 16), ft_memmove(ft_dst2 + 10, ft_dst2 + 2, 16), 16) == 0, NULL);
	write_result(7, memcmp(memmove(dst2+10, dst2+2, 16), ft_memmove(ft_dst2 + 10, ft_dst2 + 2, 16), 1) == 0, NULL);
	write_result(8, memcmp(memmove(dst2+10, dst2+2, 0), ft_memmove(ft_dst2 + 10, ft_dst2 + 2, 0), 1) == 0, NULL);
	test_end();
}

void	memchr_testset(void)
{
	char str1[50] = "hello";
	char str2[50] = "hello world";
	test_begin("memchr", "locate byte in byte string");
	write_result(1, memchr(str1, 'l', 5) == ft_memchr(str1, 'l', 5), NULL);
	write_result(2, memchr(str1, '\0', 2) == ft_memchr(str1, '\0', 2), NULL);
	write_result(3, memchr(str2, 'd', 5) == ft_memchr(str2, 'd', 5), NULL);
	write_result(4, memchr(str2, 'h', 12) == ft_memchr(str2, 'h', 12), NULL);
	write_result(5, memchr(str2, 'x', 12) == ft_memchr(str2, 'x', 12), NULL);
	test_end();

}

void	memcmp_testset(void)
{
	test_begin("memcmp", "compare byte string");
	write_result(1, memcmp("hello la zone", "hello la zone",14) == ft_memcmp("hello la zone", "hello la zone",14), NULL);
	write_result(2, memcmp("hello \0a zone", "hello \0a zone",14) == ft_memcmp("hello \0a zone", "hello \0a zone",14), NULL);
	write_result(3, memcmp("hello \0a zane", "hello \0a zone",14) == ft_memcmp("hello \0a zane", "hello \0a zone",14), NULL);
	write_result(4, memcmp("qello la zane", "hello \0a zone",14) == ft_memcmp("qello la zane", "hello \0a zone",14), NULL);
	write_result(5, memcmp("hello lh zane", "hello la zone",14) == ft_memcmp("hello lh zane", "hello la zone",14), NULL);
	write_result(6, memcmp("hello lh zane", "hello la zone", 0) == ft_memcmp("hello lh zane", "hello la zone", 0), NULL);
	test_end();
}

void	atoi_testset(void)
{
	test_begin("atoi", "convert ASCII string to integer");
	write_result(1, atoi("10") == ft_atoi("10"), NULL);
	write_result(2, atoi("42") == ft_atoi("42"), NULL);
	write_result(3, atoi("4") == ft_atoi("4"), NULL);
	write_result(4, atoi("-42") == ft_atoi("-42"), NULL);
	write_result(5, atoi("2147483647") == ft_atoi("2147483647"), NULL);
	write_result(6, atoi("-2147483648") == ft_atoi("2147483648"), NULL);
	write_result(7, atoi("42aaa42") == ft_atoi("42aaa42"), NULL);
	write_result(8, atoi("abc42") == ft_atoi("abc42"), NULL);
	write_result(9, atoi("abc42") == ft_atoi("abc42"), NULL);
	write_result(10, atoi("\t\t\n  42") == ft_atoi("\t\t\n  42"), NULL);
	write_result(11, atoi("\t\t\n  -42") == ft_atoi("\t\t\n  -42"), NULL);
	write_result(12, atoi("\t\t\n  --42") == ft_atoi("\t\t\n  --42"), NULL);
	write_result(13, atoi("\t\t\n  +-42") == ft_atoi("\t\t\n  +-42"), NULL);
	write_result(14, atoi("+42") == ft_atoi("+42"), NULL);
	test_end();
}

int		main(void)
{
	int		success_rate;
	printf("\033[1;32m===> Libft Test <===\n");
	printf("\033[0;35mby tmatis\n\n");
	memset_testset();
	bzero_testset();
	memcpy_testset();
	memccpy_testset();
	memmove_testset();
	memchr_testset();
	memcmp_testset();
	calloc_testset();
	isalpha_testset();
	isnum_testset();
	isalnum_testset();
	isascii_testset();
	isprint_testset();
	toupper_testset();
	tolower_testset();
	strlen_testset();
	strlcat_testset();
	strchr_testset();
	strdup_testset();
	strrchr_testset();
	strlcpy_testset();
	strnstr_testset();
	strncmp_testset();
	atoi_testset();
	printf("\033[01;33m=== [RESULTS FIRST PART] ===\n");
	printf("\033[0mTest total: %i\n\n", g_error + g_success);
	success_rate = (g_success * 100 / (g_success + g_error));
	if (success_rate == 100)
		printf("\033[01;32m%i %%\nFabulous 🤯", success_rate);
	else if (success_rate >= 80)
		printf("\033[01;32m%i %%\nGood 😜", success_rate);
	else if (success_rate >= 60)
		printf("\033[01;32m%i %%\nCould be better 🧐", success_rate);
	else
		printf("\033[01;31m%i %%\nRetry time 😭", success_rate);
	printf("\n");
}
