-- 코드를 입력하세요
SELECT CAR_ID, A.CAR_TYPE, FLOOR(DAILY_FEE * 30 * (1 - CAST(REPLACE(B.DISCOUNT_RATE, '%', '') AS DECIMAL) / 100)) AS FEE
FROM CAR_RENTAL_COMPANY_CAR A JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN B ON A.CAR_TYPE = B.CAR_TYPE AND DURATION_TYPE = "30일 이상"
WHERE CAR_ID NOT IN (SELECT CAR_ID
                    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
                    WHERE START_DATE<= '2022-11-30' AND END_DATE >= '2022-11-01')
    AND A.CAR_TYPE IN ("세단", "SUV")
    AND FLOOR(A.DAILY_FEE * 30 * (1 - CAST(REPLACE(B.DISCOUNT_RATE, '%', '') AS DECIMAL) / 100)) >= 500000
    AND FLOOR(A.DAILY_FEE * 30 * (1 - CAST(REPLACE(B.DISCOUNT_RATE, '%', '') AS DECIMAL) / 100)) < 2000000
ORDER BY FEE DESC, A.CAR_TYPE, CAR_ID DESC
