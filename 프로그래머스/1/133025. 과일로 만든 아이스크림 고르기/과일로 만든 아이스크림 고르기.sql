-- 코드를 입력하세요
select FLAVOR
from first_half
where total_order >= 3000 
and FLAVOR in (select FLAVOR from ICECREAM_INFO where INGREDIENT_TYPE = "fruit_based")