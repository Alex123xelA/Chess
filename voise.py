import json, pyaudio
from vosk import Model , KaldiRecognizer
def start():
    model = Model('vosk-model-small-en-us-0.15')
    rec = KaldiRecognizer(model, 16000)
    p = pyaudio.PyAudio()
    stream = p.open(format=pyaudio.paInt16, channels=1, rate=16000, input=True, frames_per_buffer=8000)
    stream.start_stream()

    def listen():
        while True:
            data = stream.read(4000, exception_on_overflow=False)
            if (rec.AcceptWaveform(data)) and len(data)>0:
                answer = json.loads(rec.Result())
                if answer['text']:
                    yield answer['text']


    komand = []
    for text in listen():

        komand = []
        text = text.split()
        if len(text)!=4:
            return 'error'
        else:
            print(text)
            #1
            if text[0] in ['eighty','a','he','hey']:komand.append('A')
            elif text[0] == 'be': komand.append('B')
            elif text[0] == 'see': komand.append('C')
            elif text[0] == 'd': komand.append('D')
            elif text[0] == 'e': komand.append('E')
            elif text[0] == 'f': komand.append('F')
            elif text[0] in ['g','gee','june']: komand.append('G')
            elif text[0] == 'h' or text[0] == 'age' or text[0] == 'each': komand.append('H')
            #2
            if text[1] == 'one': komand.append('1')
            elif text[1] == 'two' or text[1] =='too' or text[1] =='to' : komand.append('2')
            elif text[1] == 'three': komand.append('3')
            elif text[1] == 'for' or text[1] == 'four': komand.append('4')
            elif text[1] in ['five','fire']: komand.append('5')
            elif text[1] == 'six': komand.append('6')
            elif text[1] == 'seven':komand.append('7')
            elif text[1] == 'eight' or text[1] == 'a': komand.append('8')
            #3
            if text[2] in ['eighty','a','he','hey']:komand.append('A')
            elif text[2] == 'be': komand.append('B')
            elif text[2] == 'see': komand.append('C')
            elif text[2] == 'd': komand.append('D')
            elif text[2] == 'e': komand.append('E')
            elif text[2] == 'f': komand.append('F')
            elif text[2] in ['g','gee','june']: komand.append('G')
            elif text[2] == 'h' or text[2] == 'age' or text[2] == 'each': komand.append('H')
            #4
            if text[3] == 'one': komand.append('1')
            elif text[3] == 'two' or text[3] =='too' or text[3] =='to' : komand.append('2')
            elif text[3] == 'three': komand.append('3')
            elif text[3] == 'for' or text[3] == 'four': komand.append('4')
            elif text[3] in ['five','fire']: komand.append('5')
            elif text[3] == 'six': komand.append('6')
            elif text[3] == 'seven':komand.append('7')
            elif text[3] == 'eight'or text[3] == 'a': komand.append('8')

            if len(komand)==4:
                #print(komand)
                return komand[0] + komand[1] + ' ' + komand[2] + komand[3]
            else:
                return 'error'
