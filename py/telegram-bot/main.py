import time
import telebot
from threading import Thread
import server
from email_v2 import Email_box
API_TOKEN = '5570030623:AAFDPz5Z9qkGU9xjfe3BjAOChqV3llOAhPI'
bot = telebot.TeleBot(API_TOKEN)

emails = {905939371: Email_box(user="dalepa@edu.hse.ru",
                               pswrd="eyqwhchdwaprolrf",
                               server="imap.yandex.ru")}
'''
with open('data.txt') as f:
    for row in f:
        s = row.split()
        s = [int(s[0]), s[1], s[2], s[3]]
        try:
            emails[s[0]] = Email_box(user=s[2],
                                    pswrd=s[3],
                                    server=s[1] if s[1] != '-' else 'imap.yandex.ru')
        except: ...
'''
@bot.message_handler(commands=['start', 'help', 'good'])
def send_welcome(message):

    match message.text:
        case '/start':
            bot.send_message(message.chat.id, """
            Привет! Я - бот, перенаправляющий письма из твоего почтового ящика сюда, в телеграм.\n
            Чтобы я заработал, отправь свои данные моему создателю: @fatu_m""")
        case '/help':
            bot.send_message(message.chat.id, """
            Нужна помощь? Не мои проблемы.""")
        case '/good':
            bot.send_message(message.chat.id, """
            Приветствую!!! Как настроение, самочувствие?""")

@bot.message_handler(func=lambda message: message.text == 'Стоп')
def kys(message):
    bot.stop_polling()

@bot.message_handler(func=lambda message: True)
def echo_message(message):
    bot.reply_to(message, message.text)
    print(message.chat.id)


# eyqwhchdwaprolrf - pswrd
# 905939371 - айдишник

def checking():
    for user_id in emails:
        lst = emails[user_id].check_unseen(emails[user_id].get_unseen())
        for elem in lst:
            for i in elem[0]:
                bot.send_message(user_id, i)
            for j in elem[1]:
                bot.send_document(user_id, j[0], visible_file_name=j[1])

def email_checking():
    start = time.time()
    while True:
        if time.time() - start > 10:
            try:
                checking()
            except: ...

            start = time.time()


def polling():
    bot.polling()

def main():
    em = Thread(target=email_checking)
    pol = Thread(target=polling)
    serv = Thread(target=server.start_server)
    em.start()
    pol.start()
    serv.start()
    em.join()
    pol.join()
    serv.join()
main()


