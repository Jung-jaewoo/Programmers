-- 코드를 작성해주세요
WITH generation_one AS (
    SELECT id
    FROM ECOLI_DATA                            
    WHERE parent_id is null )
, generation_two AS (
    SELECT id
    FROM ECOLI_DATA                            
    WHERE parent_id in (SELECT id
                        FROM generation_one) )
SELECT id
FROM ecoli_data
WHERE parent_id in (SELECT id
                    FROM generation_two)