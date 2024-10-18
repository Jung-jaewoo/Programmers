-- 코드를 작성해주세요
SELECT id
      , CASE 
            WHEN A.rank_size <= (SELECT COUNT(*) FROM ecoli_data)*0.25 THEN 'CRITICAL'
            WHEN A.rank_size <= (SELECT COUNT(*) FROM ecoli_data)*0.5 THEN 'HIGH'
            WHEN A.rank_size <= (SELECT COUNT(*) FROM ecoli_data)*0.75 THEN 'MEDIUM'
            ELSE 'LOW' 
        END AS colony_name
FROM (SELECT id
           , RANK() OVER(ORDER BY size_of_colony DESC) AS rank_size 
      FROM ecoli_data) A
ORDER BY id