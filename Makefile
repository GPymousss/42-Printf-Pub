NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs
RM			= rm -rf

SRCS		=	ft_printf.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putnbr.c \
				ft_putptr.c \
				ft_puthex.c \
				ft_putnbr_unsigned.c

OBJS		= $(SRCS:.c=.o)

RESET		= \033[0m
BOLD		= \033[1m
ITALIC		= \033[3m
HONEY		= \033[38;5;214m
GOLD		= \033[1;38;5;220m
POLLEN		= \033[38;5;229m
STRIPE		= \033[38;5;238m
WAX			= \033[38;5;180m
RED			= \033[1;38;5;203m
CLEAR		= \033[K

GRADIENT	= 130 136 172 178 208 214 220 221 226 227
SPINNER		= ⠋ ⠙ ⠹ ⠸ ⠼ ⠴ ⠦ ⠧ ⠇ ⠏

TOTAL		= $(words $(SRCS))
COUNT		= 0
BAR_WIDTH	= 40

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n\n"
	@printf "    $(GOLD)👑$(RESET)  $(POLLEN)La reine scelle la ruche$(RESET)   $(BOLD)$(GOLD)$(NAME)$(RESET)\n"
	@$(AR) $(NAME) $(OBJS)
	@printf "\n"
	@printf "    🍯  $(GOLD)Le miel est prêt$(RESET)   $(STRIPE)·$(RESET)   $(POLLEN)$(TOTAL) alvéoles$(RESET)   $(STRIPE)·$(RESET)   $(BOLD)$(GOLD)$(NAME)$(RESET)\n"
	@printf "\n"

%.o: %.c
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@$(eval STEP=$(shell echo $$((($(COUNT)-1)*10/$(TOTAL)+1))))
	@$(eval TINT=\033[38;5;$(word $(STEP),$(GRADIENT))m)
	@$(eval FRAME=$(word $(shell echo $$(($(COUNT)%10+1))),$(SPINNER)))
	@if [ $(COUNT) -eq 1 ]; then \
		B=""; i=0; \
		while [ $$i -lt 9 ]; do \
			if [ $$((i % 2)) -eq 0 ]; then B="$$B$(GOLD)━━━━━━"; else B="$$B$(STRIPE)━━━━━━"; fi; \
			i=$$((i + 1)); \
		done; \
		printf "\n"; \
		printf "    $(GOLD)┏$$B$(GOLD)┓$(RESET)\n"; \
		printf "    $(GOLD)┃$(RESET)%54s$(GOLD)┃$(RESET)\n" ""; \
		printf "    $(GOLD)┃$(RESET)%5s👑  $(BOLD)$(GOLD)R E I N E   $(HONEY)D E S   $(GOLD)A B E I L L E S$(RESET)  🐝%6s$(GOLD)┃$(RESET)\n" "" ""; \
		printf "    $(GOLD)┃$(RESET)%14s$(ITALIC)$(WAX)libft  ·  la ruche compile$(RESET)%14s$(GOLD)┃$(RESET)\n" "" ""; \
		printf "    $(GOLD)┃$(RESET)%54s$(GOLD)┃$(RESET)\n" ""; \
		printf "    $(GOLD)┗$$B$(GOLD)┛$(RESET)\n"; \
		printf "\n"; \
	fi
	@$(CC) $(CFLAGS) -c $< -o $@ || \
		(printf "\n    $(RED)✗$(RESET)  $(BOLD)$(POLLEN)%-18s$(RESET)  $(RED)piqûre de compilation$(RESET)\n\n" $< && exit 1)
	@if [ $(COUNT) -gt 1 ]; then printf "\r$(CLEAR)\033[1A$(CLEAR)"; fi; \
	printf "    $(TINT)⬢$(RESET)  $(POLLEN)%-18s$(RESET)  $(STRIPE)%2d/%d$(RESET)\n" $< $(COUNT) $(TOTAL)
	@set -- $(GRADIENT); \
	P=$$(($(COUNT) * 100 / $(TOTAL))); \
	F=$$(($(COUNT) * $(BAR_WIDTH) / $(TOTAL))); \
	E=$$(($(BAR_WIDTH) - F)); \
	if [ $(COUNT) -eq $(TOTAL) ]; then S="🍯"; else S="$(TINT)$(FRAME) "; fi; \
	printf "\n    $$S$(RESET) "; \
	i=1; \
	while [ $$i -le $$F ]; do \
		k=$$(( (i - 1) * 10 / $(BAR_WIDTH) + 1 )); \
		eval "c=\$${$$k}"; \
		printf "\033[38;5;%sm━" $$c; \
		i=$$((i + 1)); \
	done; \
	printf "$(STRIPE)"; \
	[ $$E -gt 0 ] && printf "%0.s━" $$(seq 1 $$E); \
	printf "$(RESET)  $(BOLD)$(TINT)%3d%%$(RESET)" $$P

clean:
	@$(RM) $(OBJS)
	@printf "\n    🐝  $(POLLEN)Les alvéoles sont vidées$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "    🐝  $(BOLD)$(GOLD)$(NAME)$(RESET) $(POLLEN)s'est envolée$(RESET)\n\n"

re: fclean all

.PHONY: all clean fclean re