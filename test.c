/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:24:41 by tmatis            #+#    #+#             */
/*   Updated: 2020/10/08 21:15:59 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int		g_error = 0;
int		g_success = 0;

void	write_result(int index, int success)
{
	printf("\033[0mtest %i: ", index);
	if (success)
	{
		printf("\033[0;32m[OK]\n");
		g_success++;
	}
	else
	{
		printf("\033[0;31m[KO]\n");
		g_error++;
	}
}

void	strlen_testset(void)
{
	char str1[] = "hello";
	char str2[] = "hello word";
	char str3[] = "";

	printf("\033[1;36m===> strlen <===\n");
	printf("\033[1;35mfind length of string\n\n");
	write_result(1, ft_strlen(str1) == strlen(str1));
	write_result(2, ft_strlen(str2) == strlen(str2));
	write_result(3, ft_strlen(str3) == strlen(str3));
	printf("\n");
}

void strdup_testset(void)
{
	char str1[] = "hello";
	char str2[] = "hello word";
	char str3[] = "\0  hello";

	printf("\033[1;36m===> strdup <===\n");
	printf("\033[1;35msave a copy of a string\n\n");
	write_result(1, strcmp(strdup(str1), ft_strdup(str1)) == 0);
	write_result(2, strcmp(strdup(str2), ft_strdup(str2)) == 0);
	write_result(3, strcmp(strdup(str3), ft_strdup(str3)) == 0);
	printf("\n");
}

int	main(int argc, char **argv)
{
	printf("\033[1;32m===> Libft Test <===\n");
	printf("\033[0;35mby tmatis\n\n");
	strlen_testset();
	strdup_testset();
	printf("\033[01;33m=== [RESULTS] ===\n");
	printf("\033[0mTest total: %i\n", g_error + g_success);
	printf("\033[1;32mOK total: %i\n", g_success);
	printf("\033[1;31mKO total: %i\n", g_error);
}
