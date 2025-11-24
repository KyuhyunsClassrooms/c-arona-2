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
    printf("\n조회할 휴대폰 기종 이름을 입력하세요(한글로만, 띄어쓰기 금지): ");
    scanf(" %[^\n]", target);

    for (int i = 0; i < phoneCount; i++) {
        if (strcmp(phoneList[i].name, target) == 0) {
            printf("\n=== 조회 결과 ===\n");
            printf("기종 이름: %s\n", phoneList[i].name);
            printf("벤치마크 점수: %d\n", phoneList[i].score);
            printf("특징: %s\n", phoneList[i].features);

            // 교체 추천 판단
            if (phoneList[i].score >= 2500) {
                printf("추천: 아직 짱짱함.\n");
            } 
            else if (phoneList[i].score >= 2000) {
                printf("추천: 돈이 넘쳐나면 바꿔라.\n");
            } 
            else {
                printf("휴대폰이 아니라 벽돌 비슷한 무언가.\n");
            }
            return;
        }
    }

    printf("\n이상한 힙스터폰 쓰지 마라\n");
}

// 초기 데이터 등록
void registerPhones() {
    Phone tempList[] = {
{"아이폰17프로맥스", 3770, "A19 Pro, 최고 사양 플래그십"},
{"아이폰17프로", 3762, "A19 Pro, 프로급 카메라/성능"},
{"아이폰17", 3604, "A19, 최신 일반 모델"},
{"아이폰에어", 3638, "A19 Pro 기반, 초경량 모델"},

{"아이폰16프로", 3442, "A18 Pro, 고성능 프로 모델"},
{"아이폰16프로맥스", 3425, "A18 Pro, 대화면 + 고급 카메라"},
{"아이폰16플러스", 3316, "A18, 긴 배터리"},
{"아이폰16", 3312, "A18, 2024년 일반 모델"},
{"아이폰16e", 3232, "A18, 보급형 모델"},

{"아이폰15프로", 2885, "A17 Pro, 첫 3nm + 레이트레이싱 GPU"},
{"아이폰15프로맥스", 2876, "A17 Pro, 망원 카메라 강화"},
{"아이폰15플러스", 2547, "A16 Bionic, 대화면"},
{"아이폰15", 2545, "A16 Bionic, 안정적 성능"},

{"아이폰14프로", 2611, "A16 Bionic, 다이나믹 아일랜드"},
{"아이폰14프로맥스", 2603, "A16 Bionic, 배터리 최강"},
{"아이폰14플러스", 2259, "A15 Bionic, 대화면"},
{"아이폰14", 2259, "A15 Bionic, 2022 일반 모델"},

{"아이폰13프로맥스", 2344, "A15 Bionic, 프로모션 120Hz"},
{"아이폰13프로", 2343, "A15 Bionic, 고급 카메라"},
{"아이폰13미니", 2221, "A15 Bionic, 초소형 플래그십"},
{"아이폰13", 2214, "A15 Bionic, 성능 균형 좋음"},

{"아이폰se3", 2265, "A15 Bionic, 홈버튼 + 저가 플래그십(아이폰 13과 같은 칩)"},
{"아이폰se2", 1670, "A13 Bionic, 작지만 빠른 홈버튼 모델(아이폰 11과 같은 칩)"},

{"아이폰12프로맥스", 2124, "A14 Bionic, 큰 화면 + 좋은 카메라"},
{"아이폰12프로", 2078, "A14 Bionic, 첫 LiDAR 지원"},
{"아이폰12미니", 2032, "A14 Bionic, 초소형"},
{"아이폰12", 2029, "A14 Bionic, 5G 첫 지원 모델"},

{"아이폰11프로맥스", 1721, "A13 Bionic, 트리플 카메라"},
{"아이폰11프로", 1710, "A13 Bionic, 고급 카메라"},
{"아이폰11", 1703, "A13 Bionic, 가성비 명작"},

{"갤럭시S25울트라", 2853, "Snapdragon 8 Elite, 최고 플래그십"},
{"갤럭시S25플러스", 2842, "Snapdragon 8 Elite, 대화면 모델"},
{"갤럭시S25", 2713, "Snapdragon 8 Elite, 최신 기본형"},

{"갤럭시S24플러스", 2110, "Snapdragon 8 Gen 3, 고급형 모델"},
{"갤럭시S24울트라", 2108, "Snapdragon 8 Gen 3, 스펙 최상위"},
{"갤럭시S24", 2045, "Snapdragon 8 Gen 3, 가성비 플래그십"},

{"갤럭시S24플러스엑시노스", 2040, "Exynos 2400, 엑시노스 버전"},
{"갤럭시S24엑시노스", 1940, "Exynos 2400, 엑시노스 기본형"},

{"갤럭시S23플러스", 1922, "Snapdragon 8 Gen 2, 작년 플래그십"},
{"갤럭시S23울트라", 1911, "Snapdragon 8 Gen 2, 카메라 최상위"},
{"갤럭시S23", 1874, "Snapdragon 8 Gen 2, 기본형"},

{"갤럭시Z플립6", 1812, "Snapdragon 8 Gen 3, 최신 플립"},
{"갤럭시Z플립5", 1778, "Snapdragon 8 Gen 2, 이전 플립 모델"}
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

