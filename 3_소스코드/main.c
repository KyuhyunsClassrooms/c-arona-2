#include <stdio.h>
#include <string.h>

// 구조체 정의
typedef struct {
    char name[50];      // 기종 이름
    int score;          // 벤치마크 점수
    char features[200]; // 특징 설명
} Phone;

// 휴대폰 목록 (최대 20개)
Phone phoneList[50];
int phoneCount = 0;

// 성능 조회 및 교체 추천 기능
void checkPerformance() {
    char target[50];
    printf("\n조회할 휴대폰 기종 이름을 입력하세요: ");
    scanf(" %[^\n]", target);

    for (int i = 0; i < phoneCount; i++) {
        if (strcmp(phoneList[i].name, target) == 0) {
            printf("\n=== 조회 결과 ===\n");
            printf("기종 이름: %s\n", phoneList[i].name);
            printf("벤치마크 점수: %d\n", phoneList[i].score);
            printf("특징: %s\n", phoneList[i].features);

            // 교체 추천 판단
            if (phoneList[i].score >= 1000000) {
                printf("추천: 아직 짱짱함.\n");
            } 
            else if (phoneList[i].score >= 800000) {
                printf("추천: 돈이 넘쳐나면 바꿔라.\n");
            } 
            else {
                printf("추천: 이딴 것도 폰이냐? 당장 바꿔라.\n");
            }
            return;
        }
    }

    printf("\n이상한 힙스터 폰 쓰지 마라...\n");
}

// 초기 데이터 등록
void registerPhones() {
    Phone tempList[] = {
{"아이폰 17 프로 맥스", 3766, "A19 Pro, 최고 성능"},
{"아이폰 17 프로", 3758, "A19 Pro, 프로 등급"},
{"아이폰 에어", 3634, "A19 Pro, 경량 플래그십"},
{"아이폰 17", 3599, "A19, 우수한 효율"},
{"아이폰 16 프로", 3442, "A18 Pro, 강력한 GPU"},
{"아이폰 16 프로 맥스", 3425, "A18 Pro, 넓은 화면"},
{"아이폰 16 플러스", 3315, "A18, 대화면 베이직"},
{"아이폰 16", 3312, "A18, 기본형"},
{"아이폰 16e", 3231, "A18, 보급형 라인"},
{"아이폰 15 프로", 2885, "A17 Pro, 레이트레이싱 지원"},
{"아이폰 15 프로 맥스", 2876, "A17 Pro, 고급 카메라 경험"},
{"아이폰 15 플러스", 2547, "A16 Bionic, 대용량 배터리"},
{"아이폰 15", 2545, "A16 Bionic, 균형 잡힌 성능"},
{"아이폰 14 프로", 2610, "A16 Bionic, 프로급 디테일"},
{"아이폰 14 프로 맥스", 2602, "A16 Bionic, 큰 화면 + 성능"},
{"아이폰 14", 2259, "A15 Bionic, 기본형 모델"},
{"아이폰 14 플러스", 2259, "A15 Bionic, 화면이 큼"},
{"아이폰 13 프로 맥스", 2344, "A15 Bionic, 프리미엄 프로"},
{"아이폰 13 프로", 2343, "A15 Bionic, 고성능 + 휴대성"},
{"아이폰 13", 2214, "A15 Bionic, 밸런스형 성능"},
{"갤럭시 S25 울트라", 2853, "Snapdragon 8 Elite, 최고 플래그십"},
{"갤럭시 S25+", 2842, "Snapdragon 8 Elite, 대화면 모델"},
{"갤럭시 S25", 2713, "Snapdragon 8 Elite, 최신 기본형"},
{"갤럭시 S24+", 2110, "Snapdragon 8 Gen 3, 고급형 모델"},
{"갤럭시 S24 울트라", 2108, "Snapdragon 8 Gen 3, 스펙 최상위"},
{"갤럭시 S24", 2045, "Snapdragon 8 Gen 3, 가성비 플래그십"},
{"갤럭시 S24+ (엑시노스)", 2040, "Exynos 2400, 엑시노스 버전"},
{"갤럭시 S24 (엑시노스)", 1940, "Exynos 2400, 엑시노스 기본형"},
{"갤럭시 S23 플러스", 1922, "Snapdragon 8 Gen 2, 작년 플래그십"},
{"갤럭시 S23 울트라", 1911, "Snapdragon 8 Gen 2, 카메라 최상위"},
{"갤럭시 S23", 1874, "Snapdragon 8 Gen 2, 기본형"},
{"갤럭시 Z 플립6", 1812, "Snapdragon 8 Gen 3, 최신 플립"},
{"갤럭시 Z 플립5", 1778, "Snapdragon 8 Gen 2, 이전 플립 모델"}
    };

    // 전역 배열에 복사
    phoneCount = sizeof(tempList) / sizeof(tempList[0]);
    for (int i = 0; i < phoneCount; i++) {
        phoneList[i] = tempList[i];
    }
}

// 메인 함수
int main() {
    int menu = -1;
    printf("=== 휴대폰 성능 비교 프로그램 시작 ===\n");

    // 미리 데이터 등록
    registerPhones();

    while (1) {
        printf("\n===== 메뉴 =====\n");
        printf("1. 휴대폰 성능 조회\n");
        printf("0. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &menu);

        if (menu == 1) {
            checkPerformance();
        }
        else if (menu == 0) {
            printf("프로그램 종료!\n");
            break;
        }
        else {
            printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}

