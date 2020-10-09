/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 23:01:52 by tmatis            #+#    #+#             */
/*   Updated: 2020/10/09 23:11:48 by tmatis           ###   ########.fr       */
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

int		main(void)
{
	int		success_rate;
	printf("\033[1;32m===> Libft extra Test <===\n");
	printf("\033[0;35mby tmatis\n\n");
	strnlen_testset();
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

