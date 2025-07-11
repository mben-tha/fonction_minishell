/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:58:49 by mehdi             #+#    #+#             */
/*   Updated: 2025/06/28 12:47:15 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum	e_token_type
{
	TOK_WORD,			// 0
	TOK_PIPE,			// | = 1
	TOK_REDIR_IN,		// < = 2
	TOK_REDIR_OUT,		// > = 3
	TOK_REDIR_APPEND,	// >> = 4
	TOK_HEREDOC			// << = 5
}	t_token_type;

typedef struct s_token_word
{
	char	*word;
	int		expendable;
	struct s_token_word	*next;
}	t_token_word;

typedef struct s_token
{
	t_token_word	*word;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

void	sig_handler(int sig);

void	tokenize_line(t_token **token, char *line);
t_token_word	*split_node_word(char *str);
t_token	*new_node_operator(char *word);
t_token_word	*new_node_word(char *str);
t_token	*new_node(t_token_word *word);
void	add_back(t_token **token, t_token *new);
void	add_back_word(t_token_word **token, t_token_word *new);
int		operator(char *word);
void	ft_free_token(t_token **stack);
void	free_split(char **tab);

int	ft_countwords(char const *s, char c);
int	ft_len_word(char const *s, char c);
char	*ft_mall(char const *s, char c);
int	fr(char **result, int i);
char	**ft_split(char const *s, char c);

int		quote_not_closed(char *str);
int		len_clean_space(char *str);
void	len_clean_space2(char *str, int *i, int *len);
char    *clean_space(char *str);
void	clean_space2(char *str, char *res, int *i, int *j);
void	clean_space3(char *str, int *i);
int		is_double_operator(char *str);

void	print(t_token *stack);
void print_tokens(t_token *token);

#endif