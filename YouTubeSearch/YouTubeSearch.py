import sys
from pytube import YouTube

yt = YouTube('https://www.youtube.com/watch?v=b8vcJM_htvk')         # 동영상 링크를 이용해 YouTube 객체 생성
yt_captions = yt.captions                                           # YouTube 객체에서 caption 객체를 가져옴
my_caption = yt_captions.get_by_language_code('en')
print(my_caption.generate_srt_captions())

print("\n찾을 내용 입력: ", end = '')
search_str = sys.stdin.readline().rstrip()

list_number = []
list_time = []
list_caption = []
str = list(my_caption.generate_srt_captions().split('\n'))

for i in range(int((len(str)+1)/4)):                        # 번호별로 문서화
    list_number.append(str[i*4])                            # 자막넘버
    list_time.append(str[i*4+1])                            # 자막시간
    list_caption.append(str[i*4+2])                         # 자막내용

search_number = []                                         # 찾는 자막넘버변수

for j in range(len(list_caption)):
    if search_str in list_caption[j]:
        search_number.append(j)

for z in search_number:
    print(list_time[z])
    print(list_caption[z])