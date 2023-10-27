WITH crt1 AS (
    SELECT a.machine_id, a.process_id, abs(a.timestamp-b.timestamp) as diff
    FROM activity AS a
    INNER JOIN activity AS b 
    ON a.machine_id = b.machine_id 
    AND a.process_id = b.process_id
    AND a.activity_type = 'start'
    AND b.activity_type = 'end'
)

SELECT machine_id, ROUND(AVG(diff), 3) as processing_time
FROM crt1
group by machine_id;
