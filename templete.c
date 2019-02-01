/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:16:35 by ykliek            #+#    #+#             */
/*   Updated: 2018/12/15 15:16:37 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*make_tamplete3(t_list *head)
{
	char	*templete1;
	char	*templete16;
	char	*templete17;
	char	*templete18;
	char	*templete19;

	templete1 = (char *)malloc(22);
	templete1 = "##..\n#..\n#...\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete1, 22));
	templete16 = (char *)malloc(22);
	templete16 = "##..\n.#..\n.#..\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete16, 22));
	templete17 = (char *)malloc(22);
	templete17 = "..#.\n###.\n....\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete17, 22));
	templete18 = (char *)malloc(22);
	templete18 = "#...\n#...\n##..\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete18, 22));
	templete19 = (char *)malloc(22);
	templete19 = "###.\n..#.\n....\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete19, 22));
	return (head);
}

t_list	*make_tamplete2(t_list *head)
{
	char	*templete11;
	char	*templete12;
	char	*templete13;
	char	*templete14;
	char	*templete15;

	templete11 = (char *)malloc(22);
	templete11 = "###.\n.#.\n....\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete11, 22));
	templete12 = (char *)malloc(22);
	templete12 = ".#..\n##..\n.#..\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete12, 22));
	templete13 = (char *)malloc(22);
	templete13 = "###.\n..#.\n....\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete13, 22));
	templete14 = (char *)malloc(22);
	templete14 = "#...\n###.\n....\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete14, 22));
	templete15 = (char *)malloc(22);
	templete15 = "#...\n##..\n#...\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete15, 22));
	head = make_tamplete3(head);
	return (head);
}

t_list	*make_tamplete1(t_list *head)
{
	char	*templete6;
	char	*templete7;
	char	*templete8;
	char	*templete9;
	char	*templete10;

	templete6 = (char *)malloc(22);
	templete6 = ".#..\n##.\n#...\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete6, 22));
	templete7 = (char *)malloc(22);
	templete7 = ".##.\n##..\n....\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete7, 22));
	templete8 = (char *)malloc(22);
	templete8 = "#...\n##..\n.#..\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete8, 22));
	templete9 = (char *)malloc(22);
	templete9 = ".#..\n###.\n....\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete9, 22));
	templete10 = (char *)malloc(22);
	templete10 = "#...\n##..\n#...\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete10, 22));
	head = make_tamplete2(head);
	return (head);
}

t_list	*make_tamplete(void)
{
	t_list	*head;
	char	*templete2;
	char	*templete3;
	char	*templete4;
	char	*templete5;

	head = NULL;
	templete2 = (char *)malloc(22);
	templete2 = "##..\n##..\n....\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete2, 22));
	templete3 = (char *)malloc(22);
	templete3 = "####\n....\n....\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete3, 22));
	templete4 = (char *)malloc(22);
	templete4 = "##..\n.##.\n....\n....\n\0";
	ft_lstadd(&head, ft_lstnew(templete4, 22));
	templete5 = (char *)malloc(22);
	templete5 = "#...\n#...\n#...\n#...\n\0";
	ft_lstadd(&head, ft_lstnew(templete5, 22));
	head = make_tamplete1(head);
	return (head);
}
