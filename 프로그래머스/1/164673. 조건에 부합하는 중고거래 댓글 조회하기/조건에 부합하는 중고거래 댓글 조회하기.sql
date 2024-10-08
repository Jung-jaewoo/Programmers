-- 코드를 입력하세요
select a.TITLE, a.BOARD_ID, b.REPLY_ID, b.WRITER_ID, b.CONTENTS, DATE_FORMAT(b.CREATED_DATE,"%Y-%m-%d") as CREATED_DATE
from USED_GOODS_BOARD as a 
join USED_GOODS_REPLY as b on a.BOARD_ID = b.BOARD_ID
where year(a.CREATED_DATE) = "2022" and month(a.CREATED_DATE) = "10"
order by b.CREATED_DATE ASC, a.TITLE ASC;
