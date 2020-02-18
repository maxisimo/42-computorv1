NAME = computorv1
BLUE1 =  \033[38;5;51m
BLUE2 = \033[38;5;99m
END = \033[0m

SRC = main.c \
	  parser.c \
	  reduce.c \
	  display.c \
	  solve.c \
	  utils.c \
	  utils2.c

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

all: start $(NAME)

$(NAME) : $(OBJ)
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -lm
	@echo "$(BLUE2)Done$(END)";

start:
	@echo "\n";
	@echo "			\\033[38;5;45m      ::::::::   ::::::::    :::   :::   :::::::::  :::    ::: ::::::::::: ::::::::  :::::::::       :::     :::   ::: $(END)";
	@echo "			\\033[38;5;39m    :+:    :+: :+:    :+:  :+:+: :+:+:  :+:    :+: :+:    :+:     :+:    :+:    :+: :+:    :+:      :+:     :+: :+:+:  $(END)";
	@echo "			\\033[38;5;33m   +:+        +:+    +:+ +:+ +:+:+ +:+ +:+    +:+ +:+    +:+     +:+    +:+    +:+ +:+    +:+      +:+     +:+   +:+   $(END)";
	@echo "			\\033[38;5;26m  +#+        +#+    +:+ +#+  +:+  +#+ +#++:++#+  +#+    +:+     +#+    +#+    +:+ +#++:++#:       +#+     +:+   +#+    $(END)";
	@echo "			\\033[38;5;21m +#+        +#+    +#+ +#+       +#+ +#+        +#+    +#+     +#+    +#+    +#+ +#+    +#+       +#+   +#+    +#+     $(END)";
	@echo "			\\033[38;5;20m#+#    #+# #+#    #+# #+#       #+# #+#        #+#    #+#     #+#    #+#    #+# #+#    #+#        #+#+#+#     #+#      $(END)";
	@echo "			\\033[38;5;19m########   ########  ###       ### ###         ########      ###     ########  ###    ###          ###     #######     $(END)";
	@echo "\n";
	@echo "$(BLUE1)[COMPUTORV1] :$(END) $(BLUE2)Compiling C files ...$(END)";

clean:
	@echo "\033[K$(BLUE1)[COMPUTORV1] :$(END) $(BLUE2)Cleaning object files ...$(END)";
	@/bin/rm -rf $(OBJ)
	@echo "$(BLUE2)Done$(END)";

fclean: clean
	@echo "\033[K$(BLUE1)[COMPUTORV1] :$(END) $(BLUE2)Cleaning binary file ...$(END)";
	@/bin/rm -rf $(NAME)
	@echo "$(BLUE2)Done$(END)";

re : fclean all

.PHONY: all clean fclean re
