import time
import telebot
from threading import Thread
import server

from email_v2 import Email_box
API_TOKEN = '5570030623:AAFDPz5Z9qkGU9xjfe3BjAOChqV3llOAhPI'
bot = telebot.TeleBot(API_TOKEN)

my_em = Email_box()
# Handle '/start' and '/help'
@bot.message_handler(commands=['start'])
def send_welcome(message):
    bot.reply_to(message, """\
Hi there, I am EchoBot.
I am here to echo your kind words back to you. Just say anything nice and I'll say the exact same thing to you!\
""")

@bot.message_handler(commands=['help'])
def send_something(message):
    bot.reply_to(message, """\
    Bruh...""")
    bot.stop_polling()

@bot.message_handler(commands=['check_email'])
def check(message):
    ...

@bot.message_handler(func=lambda message: True)
def echo_message(message):
    bot.reply_to(message, message.text)
    print(message.chat.id)

# eyqwhchdwaprolrf - pswrd
# 905939371 - айдишник

def checking(bot):
    lst = my_em.check_unseen(my_em.get_unseen())
    for elem in lst:
        for i in elem[0]:
            bot.send_message(905939371, i)
        for j in elem[1]:
            bot.send_document(905939371, j[0], visible_file_name=j[1])

def email_checking():
    start = time.time()
    while True:
        if time.time() - start > 60:
            checking(bot)

Thread(target=email_checking).start()
Thread(target=server.start_server).start()
bot.infinity_polling()

