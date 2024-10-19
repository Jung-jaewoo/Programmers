-- 코드를 작성해주세요
WITH RECURSIVE generations AS (
    -- 1세대 개체 찾기
    SELECT id, 1 AS generation
    FROM ECOLI_DATA
    WHERE parent_id IS NULL
    
    UNION ALL
    
    -- 이후 세대 개체 찾기
    SELECT e.id, g.generation + 1
    FROM ECOLI_DATA e
    JOIN generations g ON e.parent_id = g.id
)
SELECT COUNT(g.id) AS COUNT, g.generation AS GENERATION
FROM generations g
LEFT JOIN ECOLI_DATA e ON g.id = e.parent_id
WHERE e.id IS NULL
GROUP BY g.generation
ORDER BY g.generation;
