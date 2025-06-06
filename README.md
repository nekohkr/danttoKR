# danttoKR
danttoKR는 ATSC 3.0를 MPEG-2 TS로 변환하는 도구입니다.
현재는 ROUTE/DASH 방식만 지원하며, MMT 방식(KBS1 등)은 지원하지 않습니다.

## 사용 방법
```
./danttoKR.exe <input> <output.ts>
```
현재는 UHD 셋탑박스 AN-US800K의 자체 컨테이너 형식만 지원하며, 다른 포맷은 지원하지 않습니다.

## 암호화
이 프로젝트는 복호화 기능을 포함하지 않습니다.
따라서 암호화되지 않은 지역 방송(TJB, KNN 등)에만 사용할 수 있습니다.

## TODO
- LLS 파싱
- MMT 지원
- EPG 변환
- pcap 입력 지원
