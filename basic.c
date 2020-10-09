/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:24:41 by tmatis            #+#    #+#             */
/*   Updated: 2020/10/10 00:10:14 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
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

void	memcpy_testset(void)
{
	char str1[6] = "hello";
	char str2[11] = "hello world";
	char ft_dst1[20];
	char ft_dst2[20];
	char dst1[20];
	char dst2[20];

	test_begin("memcpy", "copy n byte of memory");
	write_result(1, memcmp(memcpy(dst1, str1, 6), ft_memcpy(ft_dst1, str1, 6), 6) == 0, NULL);
	write_result(2, memcmp(memcpy(dst2, str2, 10), ft_memcpy(ft_dst2, str2, 10), 10) == 0, NULL);
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

int		main(void)
{
	int		success_rate;
	printf("\033[1;32m===> Libft Test <===\n");
	printf("\033[0;35mby tmatis\n\n");
	memcpy_testset();
	strlen_testset();
	strdup_testset();
	strcpy_testset();
	strncpy_testset();
	strcat_testset();
	strncat_testset();
	printf("\033[01;33m=== [RESULTS] ===\n");
	printf("\033[0mTest total: %i\n\n", g_error + g_success);
	success_rate = (g_success * 100 / (g_success + g_error));
	if (success_rate == 100)
		printf("\033[01;32m%i %%\nFabulous 🤯 test the bonus", success_rate);
	else if (success_rate >= 80)
		printf("\033[01;32m%i %%\nGood 😜", success_rate);
	else if (success_rate >= 60)
		printf("\033[01;32m%i %%\nCould be better 🧐", success_rate);
	else
		printf("\033[01;31m%i %%\nRetry time 😭", success_rate);
	printf("\n");
}
