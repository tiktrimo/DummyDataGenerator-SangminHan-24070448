# DummyDataGenerator-SangminHan-24070448

> **[POC Stage]** 현재 개념 검증(Proof of Concept) 단계입니다. 구현 코드는 포함되지 않습니다.

## POC: Dummy 데이터 생성 Tool

테스트용 더미 데이터를 생성하여 데이터 저장소에 자동으로 추가하는 도구 PoC 레포지토리입니다.

## 개발 환경

- **언어**: C++
- **IDE**: Visual Studio

## 목적

- 시료(Sample) 및 주문(Order) 더미 데이터 자동 생성 구조 검증
- 생성된 데이터를 JSON 파일 저장소에 직접 추가

## 폴더 구조

```
DummyDataGenerator-SangminHan-24070448/
  src/
    generator/  - 시료·주문 더미 데이터 생성 로직 (*.h, *.cpp)
  data/         - 생성된 더미 데이터 저장 위치
  DummyDataGenerator.sln
```

## 빌드 및 실행 결과

```
[생성 완료]
  시료 : 8종  -> data/samples.dat
  주문 : 20건 -> data/orders.dat

[생성된 시료] 실리콘 웨이퍼-8인치 / GaN 에피택셜 / SiC 파워기판 등 8종
[주문 샘플]   seed=42로 재현 가능한 랜덤 데이터 (삼성전자, SK하이닉스 등)
```

- Build: MSBuild Debug|x64 — 에러/경고 없음
- DataPersistence / DataMonitor POC와 동일 파일 포맷 호환 확인

## 생성 데이터 항목

| 항목 | 내용 |
|------|------|
| 시료 (Sample) | ID, 이름, 평균 생산시간, 수율, 재고 수량 |
| 주문 (Order) | 주문번호, 시료ID, 고객명, 수량, 상태 |
