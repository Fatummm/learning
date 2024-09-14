import email
from email.header import decode_header
import imaplib

def get_coding(topic):
    kodirovka = ''
    i = 2
    while i < len(topic) and topic[i] != '?':
        kodirovka += topic[i]
        i += 1
    return kodirovka

def check_message(msg):
    counter = 1
    ans = ['']
    ans[counter - 1] = "\U0001F353\U0001FAD0Вам пришло новое сообщение:\U0001FAD0\U0001F353\n"
    ans[counter - 1] += 'От: '
    name = msg.get('From').split()[0]
    codec = get_coding(name)
    try:
        name = decode_header(name)[0][0].decode(encoding=codec)
    except: ...
    ans[counter - 1] += name + ' '
    try:
        ans[counter - 1] += msg.get('From').split()[1] + '\n'
    except: ans[counter-1] += '\n'
    files = []
    topic = msg.get("Subject")
    if topic:
        codec = get_coding(topic)
        topic = decode_header(topic)[0][0].decode(encoding=codec)
    else:
        topic = '-'
    ans[counter - 1] += 'Тема: ' + topic + '\n\n'

    for part in msg.walk():
        if part.get_content_type() == 'text/plain':
            charset = part.get_content_charset()
            try:
                body = part.get_payload(decode=True).decode(charset if charset else "utf-8")
            except:
                body = part.get_payload(decode=True).decode("iso-8859-1")
            if len(ans[counter-1]) + len(body) > 4000:
                ans.append('')
                counter += 1
                while len(body) > 4000:
                    ans[counter - 1] += body[:3500]
                    body = body[2500:]
                    ans.append('')
                    counter += 1
            ans[counter-1] += body
        elif part.get("Content-Disposition") and \
                "attachment" in part.get("Content-Disposition"):

            filename = part.get_filename()
            try:
                codec = get_coding(filename)
                filename = decode_header(filename)[0][0].decode(encoding=codec)
            except: ...
            if filename:
                file_data = part.get_payload(decode=True)
                files.append([file_data, filename])

        elif "image" in part.get_content_type() and part.get("Content-ID"):
            image_data = part.get_payload(decode=True)
            filename = part.get_filename()
            try:
                codec = get_coding(filename)
                filename = decode_header(filename)[0][0].decode(encoding=codec)
            except: ...
            files.append([image_data, filename])

    return [ans, files]

class Email_box:
    def __init__(self, user="dalepa@edu.hse.ru",
                 pswrd="eyqwhchdwaprolrf",
                 server="imap.yandex.ru"):
        self.password = pswrd
        self.username = user
        self.server = server


        self.imap = imaplib.IMAP4_SSL(self.server)
        self.imap.login(self.username, self.password)
        self.imap.select("Inbox")

    def get_unseen(self):
        unseen = self.imap.search(None, 'UNSEEN')[1][0]
        unseen = str(unseen)[2:-1].split()
        return unseen

    def check_unseen(self, list_of_unseen):
        lst = []
        for message_number in list_of_unseen:
            _, data = self.imap.fetch(message_number, "(RFC822)")
            message = email.message_from_bytes(data[0][1])
            lst += [check_message(message)]
        return lst



#my_em = Email_box()
#print(my_em.get_unseen())
#unseen_list = my_em.check_unseen(my_em.get_unseen())
#for elem in unseen_list:
#    print(elem[0])
username = "dalepa@edu.hse.ru"
imap_server = "imap.yandex.ru"
mail_pass = "eyqwhchdwaprolrf"


#imap = imaplib.IMAP4_SSL(imap_server)
#imap.login(username, mail_pass)
#imap.select("Inbox")
#msgnums = str(imap.search(None, "ALL")[1][0])[2:-1].split()
#print(msgnums)
#msg = '20'
#_, data = imap.fetch(msg, "(RFC822)")
#message = email.message_from_bytes(data[0][1])

#print(message.get('From').split()[1])

'''
for msg in msgnums:
    _, data = imap.fetch(msg, "(RFC822)")
    message = email.message_from_bytes(data[0][1])
    topic = message.get('Subject')
    codec = get_coding(topic)
    topic = decode_header(topic)[0][0].decode(encoding=codec)
    print(topic)
'''

