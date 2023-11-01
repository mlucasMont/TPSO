all: jogoUI motor bot

jogoUI: jogoUI.c
    gcc -o jogoUI jogoUI.c -lncurses

motor: motor_jogo.c
    gcc -o motor motor_jogo.c
    
bot: bot.c
    gcc -o bot bot.c

clean:
    rm -f jogoUI motor bot
