#include "ft_sh.h"

void	init_line(t_line *line)
{
	line->len = INIT_LINE_SIZE;
	if (!(line->buf = (char *)ft_memalloc(INIT_LINE_SIZE + 1)))
		ft_memerr();
}

void	resize_line_buf(t_line *line)
{
	char	*new_line;

	line->len *= 2;
	if (!(new_line = (char *)ft_memalloc(line->len + 1)))
		ft_memerr();
	ft_strcpy(new_line, line->buf);
	free(line->buf);
	line->buf = new_line;
	line_sgt(line);
}

void	reset_line(t_line *line)
{
	line->len = INIT_LINE_SIZE;
	ft_bzero(line->buf, line->len);
	line->i = 0;
	line->cp = PROMPT_LEN_UI;
	ioctl(STDIN, TIOCGWINSZ, &line->w);
	line_sgt(line);
}
