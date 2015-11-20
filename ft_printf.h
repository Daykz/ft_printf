/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 23:50:35 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/29 16:56:15 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_flag
{
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_flag;

typedef struct	s_precis
{
	int			pt;
	int			min;
	int			max;
	int			point;
	int			i;
	int			j;
	int			precis;
	int			hash;
	int			moins;
	int			plus;
	int			space;
	int			zero;
	int			negatif;
	int			convers;
	int			modulo;
	int			lim;
}				t_precis;

char			*ft_sizehmtoa(size_t n);
char			*ft_mhmtoa(uintmax_t n);
char			*ft_lhmtoa(unsigned long int n);
char			*ft_shmtoa(unsigned short int n);
char			*ft_hmtoa(unsigned int n);
char			*ft_sizehtoa(size_t n);
char			*ft_mhtoa(uintmax_t n);
char			*ft_lhtoa(unsigned long int n);
char			*ft_shtoa(unsigned short int n);
char			*ft_htoa(unsigned int n);
char			*ft_sizeutoa(size_t n);
char			*ft_lutoa(unsigned long int n);
char			*ft_sutoa(unsigned short int n);
char			*ft_sizeotoa(size_t n);
char			*ft_motoa(uintmax_t n);
char			*ft_lotoa(unsigned long int n);
char			*ft_sotoa(unsigned short int n);
char			*ft_otoa(unsigned int n);
char			*ft_stoa(short int n);
char			*ft_ltoa(long long int n);
int				ft_printf(char *format, ...);
void			ft_putnbr_long(long int n);
int				check_flags(char *flag, t_precis *nb);
void			init_flag(t_flag *flag);
int				check_modif_len(t_flag *flag, char *str, t_precis *nb);
void			check_precis(t_precis *nb, char *str);
int				precis_min(t_precis *nb, char *str);
int				precis_max(t_precis *nb, char *str);
int				check_convers(t_flag *flag, va_list ap, char *s, t_precis *nb);
int				conv_s(va_list ap, t_precis *nb);
int				conv_di(va_list ap, t_flag *flag, t_precis *nb);
int				di_len_h(va_list ap, t_precis *nb);
int				di_len_hh(va_list ap, t_precis *nb);
int				di_len_l(va_list ap, t_precis *nb);
int				di_len_ll(va_list ap, t_precis *nb);
int				di_len_j(va_list ap, t_precis *nb);
int				di_len_z(va_list ap, t_precis *nb);
int				di_len(va_list ap, t_precis *nb);
int				o_len_h(va_list ap, t_precis *nb);
int				o_len_hh(va_list ap);
int				o_len_l(va_list ap, t_precis *nb);
int				o_len_ll(va_list ap, t_precis *nb);
int				o_len_j(va_list ap, t_precis *nb);
int				o_len_z(va_list ap, t_precis *nb);
int				o_len(va_list ap, t_precis *nb);
int				u_len_h(va_list ap, t_precis *nb);
int				u_len_hh(va_list ap);
int				u_len_l(va_list ap, t_precis *nb);
int				u_len_ll(va_list ap, t_precis *nb);
int				u_len_j(va_list ap, t_precis *nb);
int				u_len_z(va_list ap, t_precis *nb);
int				u_len(va_list ap, t_precis *nb);
int				x_len_h(va_list ap, t_precis *nb);
int				x_len_hh(va_list ap);
int				x_len_l(va_list ap, t_precis *nb);
int				x_len_ll(va_list ap, t_precis *nb);
int				x_len_j(va_list ap, t_precis *nb);
int				x_len_z(va_list ap, t_precis *nb);
int				x_len(va_list ap, t_precis *nb);
int				xmaj_len_h(va_list ap, t_precis *nb);
int				xmaj_len_hh(va_list ap);
int				xmaj_len_l(va_list ap, t_precis *nb);
int				xmaj_len_ll(va_list ap, t_precis *nb);
int				xmaj_len_j(va_list ap, t_precis *nb);
int				xmaj_len_z(va_list ap, t_precis *nb);
int				xmaj_len(va_list ap, t_precis *nb);
int				conv_u(va_list ap, t_flag *flag, t_precis *nb);
int				conv_o(va_list ap, t_flag *flag, t_precis *nb);
int				conv_x(va_list ap, t_flag *flag, t_precis *nb);
int				conv_xmaj(va_list ap, t_flag *flag, t_precis *nb);
int				conv_c(va_list ap, t_precis *nb);
int				conv_p(va_list ap, t_precis *nb);
void			init_precis(t_precis *nb);
int				ft_strprecis(char *str, t_precis *nb);
int				ft_intprecis(char *str, t_precis *nb);
int				intprec(char *str, t_precis *nb);
int				intprecis(char *str, t_precis *nb);
void			init(t_flag *flag, t_precis *nb);
char			*basebinary(int n);
int				basedecimal(char *bin);
char			*ft_strrev(char	*s);
char			*displaywchar(char **tab, int nb);
char			*splitbinary(char *bin, int	nbdiv);
char			*fillmask(char *bin, char *tmp, int masklen);
char			*maskunicode(char *bin, int masklen);
int				conv_lc(va_list ap, t_precis *nb);
int				printwchar(int tmp, char *newstr, t_precis *nb);
int				conv_ls(va_list ap, t_precis *nb);
int				stop_convers(char *str, t_precis *nb);
int				false_convers(char c);
int				double_modulo(t_precis *nb, char *str);
int				char_limit(int n);
int				uchar_limit(int n);
int				size_fields_str(char *str, t_precis *nb);
int				check_double_modulo(char *str, t_precis *nb);
int				size_fields_char(t_precis *nb);
int				size_fields_pointer(size_t n, t_precis *nb);
int				size_fields_nul(t_precis *nb);
int				zero_fill(char *str, t_precis *nb);
int				zero_fill_char(t_precis *nb);
char			*ft_utoa(unsigned int n);
int				zero_with_less(t_precis *nb);
int				check_precision(char *str, t_precis *nb, int n);
int				null_with_precis_s(t_precis *nb);
int				null_with_precis_c(t_precis *nb);
int				useles_char(t_precis *nb, char c);
int				precis_for_char(t_precis *nb);
int				zero_for_p(t_precis *nb);
int				precis_for_wchar(int *len, t_precis *nb, char *str);
int				max_wchar(t_precis *nb, int len);
int				conv_ls_null(int i);
int				check_convers1(t_flag *flag, va_list ap, char c, t_precis *nb);
int				check_convers2(t_flag *flag, va_list ap, char c, t_precis *nb);
int				check_convers3(t_flag *flag, va_list ap, char c, t_precis *nb);
int				check_convers4(va_list ap, char c, t_precis *nb);
int				check_convers5(va_list ap, char c, t_precis *nb);
int				false_convers2(t_precis *nb, char c);
int				check_convers_null(int *len);
void			distrib(t_precis *nb, t_flag *flag, char *format);
void			modul(t_precis *nb, t_flag *flag, char *format, int *len);
void			modul_alo(t_precis *nb, t_flag *flag, char *format);
void			put_char(char c, int *len);
void			intprecis2(t_precis *nb, int *j, int *len, char *str);
void			strprecis(t_precis *nb, int *i, int *x, int *j);
void			zero_fill1(t_precis *nb, int *diff);
int				zero_fill2(t_precis *nb, char *str, int *diff, int *j);

#endif
