-- 코드를 입력하세요
SELECT MEMBER_NAME, REVIEW_TEXT, DATE_FORMAT(REVIEW_DATE,"%Y-%m-%d") AS REVIEW_DATE
FROM MEMBER_PROFILE A JOIN REST_REVIEW B ON A.MEMBER_ID = B.MEMBER_ID
WHERE A.MEMBER_ID IN (SELECT MEMBER_ID 
                    FROM REST_REVIEW
                    GROUP BY MEMBER_ID
                    HAVING COUNT(REVIEW_ID) = (SELECT COUNT(REVIEW_ID)
                                                FROM REST_REVIEW
                                                GROUP BY MEMBER_ID
                                                ORDER BY COUNT(REVIEW_ID) DESC
                                                LIMIT 1))
ORDER BY REVIEW_DATE, REVIEW_TEXT 
