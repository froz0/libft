/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 23:01:52 by tmatis            #+#    #+#             */
/*   Updated: 2020/10/16 17:43:12 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
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
	printf("\n");
	if (g_testset_s < g_testset_e + g_testset_s)
		printf("\033[0;31m%i/%i: KO 🥺", g_testset_s , g_testset_s + g_testset_e);
	else
		printf("\033[0;32m%i/%i: OK 🥳", g_testset_s , g_testset_s + g_testset_e);
	g_error += g_testset_e;
	g_success += g_testset_s;
	printf("\n\n");
}

void	strcpy_testset(void)
{
	char str1[6] = "hello";
	char str2[13] = "hello world";
	char str3[9] = "\0  hello";
	char dst1[6];
	char dst2[13];
	char dst3[9];
	char ft_dst1[6];
	char ft_dst2[13];
	char ft_dst3[9];

	test_begin("strcpy", "strcpy() functions copy the string src to dst (including \nthe terminating 0 character)");
	write_result(1, strcmp(strcpy(dst1, str1), ft_strcpy(ft_dst1, str1)) == 0, "Test with \"hello\"");
	write_result(2, strcmp(str1, ft_dst1) == 0, "Test if the dest is well filled");
	write_result(3, strcmp(strcpy(dst2, str2), ft_strcpy(ft_dst2, str2)) == 0, "Test with \"hello world\"");
	write_result(4, strcmp(strcpy(dst3, str3), ft_strcpy(ft_dst3, str3)) == 0, "Test with \"0 hello\"");
	test_end();
}

void	strncpy_testset(void)
{
	char str1[6] = "hello";
	char str2[12] = "hello word";
	char str3[9] = "\0  hello";
	char dst1[6];
	char dst1_2[12];
	char dst2[12];
	char dst2_2[12];
	char dst3[9];
	char ft_dst1[6];
	char ft_dst1_2[12];
	char ft_dst2[12];
	char ft_dst2_2[12];
	char ft_dst3[9];

	test_begin("strncpy", "strncpy() functions copy the string src to dst fill with 0 the left char");
	write_result(1, memcmp(strncpy(dst1, str1, 6), ft_strncpy(ft_dst1,str1, 6) ,6) == 0, NULL);
	write_result(2, memcmp(str1, ft_dst1, 6) == 0, "Test if the dest is well filled");
	write_result(3, memcmp(strncpy(dst1_2, str1, 12), ft_strncpy(ft_dst1_2,str1, 12) , 12) == 0, NULL);
	write_result(4, memcmp(strncpy(dst2, str2, 12), ft_strncpy(ft_dst2,str2, 12) , 12) == 0, NULL);
	write_result(5, memcmp(strncpy(dst2_2, str2, 5), ft_strncpy(ft_dst2_2, str2, 5) , 5) == 0, NULL);
	write_result(6, memcmp(strncpy(dst3, str3, 9), ft_strncpy(ft_dst3, str3, 9) , 9) == 0, NULL);
	test_end();
}

void	strcat_testset(void)
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
	test_begin("strcat", "The strcat functions append a copy of the string s2 to the end\nof s1, then add 0");
	write_result(1, strcmp(strcat(str1, str1_2), ft_strcat(ft_str1, str1_2)) == 0, NULL);
	write_result(2, strcmp(strcat(str2, str2_2), ft_strcat(ft_str2, str2_2)) == 0, NULL);
	write_result(3, strcmp(strcat(str3, str3_2), ft_strcat(ft_str3, str3_2)) == 0, NULL);
	test_end();
}

void	strncat_testset(void)
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
	test_begin("strncat", "strncat same but i < n");
	write_result(1, strcmp(strncat(str1, str1_2, 4), ft_strncat(ft_str1, str1_2, 4)) == 0, NULL);
	write_result(2, strcmp(strncat(str2, str2_2, 5), ft_strncat(ft_str2, str2_2, 5)) == 0, NULL);
	write_result(3, strcmp(strncat(str3, str3_2, 10), ft_strncat(ft_str3, str3_2, 10)) == 0, NULL);
	test_end();
}

void	strnlen_testset(void)
{
	char str1[6] = "hello";
	char str2[12] = "hello word";
	char str3[9] = "\0  hello";
	
	test_begin("strnlen", "same as strlen but with i < n");
	write_result(1, strnlen(str1, 6) == ft_strnlen(str1, 6), NULL);
	write_result(2, strnlen(str1, 11) == ft_strnlen(str1, 11), NULL);
	write_result(3, strnlen(str1, 15) == ft_strnlen(str1, 15), NULL);
	test_end();
}

void	strcmp_testset(void)
{
	test_begin("strcmp", "compare strings");
	write_result(1, strcmp("salut la zone", "salut la zone") == ft_strcmp("salut la zone", "salut la zone"), NULL);
	write_result(2, strcmp("salut la zona", "salut la zona") == ft_strcmp("salut la zona", "salut la zona"), NULL);
	write_result(3, strcmp("salut la zon", "salut la zone") == ft_strcmp("salut la zon", "salut la zone"), NULL);
	write_result(4, strcmp("salut la zone", "salut la zon") == ft_strcmp("salut la zone", "salut la zon"), NULL);
	write_result(5, strcmp("", "") == ft_strcmp("", ""), NULL);
	write_result(6, strcmp("aalut la zone", "salut la zone") == ft_strcmp("aalut la zone", "salut la zone"), NULL);
	write_result(7, strcmp("salut\0 lq zone", "salut\0 la zone") == ft_strcmp("salut\0 lq zone", "salut\0 la zone"), NULL);
	test_end();
}

int		main(void)
{
	int		success_rate;
	printf("\033[1;32m===> Libft extra Test <===\n");
	printf("\033[0;35mby tmatis\n\n");
	strnlen_testset();
	strcpy_testset();
	strcat_testset();
	strncat_testset();
	strcmp_testset();
	printf("\033[01;33m=== [RESULTS] ===\n");
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
