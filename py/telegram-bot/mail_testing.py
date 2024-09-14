import time
import threading
from telegram import Bot
from telebot import Updater, CommandHandler, MessageHandler, Filters

# Настройки
TOKEN = 'your_telegram_bot_token'
chat_id = 'your_chat_id'

bot = Bot(token=TOKEN)

def send_hello():
    while True:
        bot.send_message(chat_id=chat_id, text='Hello')
        time.sleep(10)

def start(update, context):
    update.message.reply_text('Бот запущен!')

def echo(update, context):
    update.message.reply_text(update.message.text)

def main():
    updater = Updater(TOKEN)

    dispatcher = updater.dispatcher
    dispatcher.add_handler(CommandHandler('start', start))
    dispatcher.add_handler(MessageHandler(Filters.text & ~Filters.command, echo))

    # Запускаем поток для отправки сообщений
    threading.Thread(target=send_hello, daemon=True).start()

    updater.start_polling()
    updater.idle()

if __name__ == '__main__':
    main()