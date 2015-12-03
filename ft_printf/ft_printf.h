/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:52:13 by vdruta            #+#    #+#             */
/*   Updated: 2015/12/03 20:23:26 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <inttypes.h>
# define CONVERSIONS "sSpdDioOuUxXcC"
# define FLAGS "#0-+ jzhl123456789"

typedef struct		s_arg
{
	int			flag_hash;
	int			flag_zero;
	int			flag_minus;
	int			flag_plus;
	int			flag_space;
	int			lm_j;
	int			lm_z;
	int			lm_h;
	int			lm_hh;
	int			lm_l;
	int			lm_ll;
}					t_arg;

int		ft_printf(const char *format, ...);

char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putwchar(wchar_t wc);
int		ft_wcharsize(wchar_t wc);
void	ft_putstr(char const *s);
size_t	ft_strlen(const char *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	ft_putnbr(int n);
char	*ft_itoabase(uintmax_t val, int base);
char	*ft_itoabbase(uintmax_t val, int base);
char	*ft_intmax_t_to_ascii_base(intmax_t val, int base);
char	*ft_uintmax_t_to_ascii_base(uintmax_t val, int base);
char	*ft_strjoin(const char *s1, const char *s2);

void	ft_process_s_(va_list ap, int *bytes, t_arg arg);
void	ft_process_ss_(va_list ap, int *bytes);
void	ft_process_d_(va_list ap, int *bytes, char *descriptor);
void	ft_process_dd_(va_list ap, int *bytes, char *descriptor);
void	ft_process_p_(va_list ap, int *bytes);
void	ft_process_c_(va_list ap, int *bytes, char *descriptor);
void	ft_process_cc_(va_list ap, int *bytes);
void	ft_process_o_(va_list ap, int *bytes, char *descriptor);
void	ft_process_oo_(va_list ap, int *bytes, char *descriptor);
void	ft_process_u_(va_list ap, int *bytes, char *descriptor);
void	ft_process_uu_(va_list ap, int *bytes);
void	ft_process_x_(va_list ap, int *bytes, char *descriptor);
void	ft_process_xx_(va_list ap, int *bytes, char *descriptor);


#endif
