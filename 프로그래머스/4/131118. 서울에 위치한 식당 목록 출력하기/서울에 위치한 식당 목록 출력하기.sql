-- 코드를 입력하세요
select a.REST_ID, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS, round(avg(review_score),2) as SCORE
from rest_info a natural join rest_review b 
where address like "서울%"
group by a.rest_id
order by score desc, favorites desc