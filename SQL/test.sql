SELECT DATE_TRUNC('week',date) AS "Week",
       COUNT(CASE WHEN league = 'mlb' THEN team ELSE NULL END) AS "MLB Games",
       COUNT(CASE WHEN league = 'nba' THEN team ELSE NULL END) AS "NBA Games",
       COUNT(CASE WHEN league = 'nfl' THEN team ELSE NULL END) AS "NFL Games",
       COUNT(CASE WHEN league = 'nhl' THEN team ELSE NULL END) AS "NHL Games"
  FROM benn.professional_sports_game_log
 WHERE location = 'home'
   AND date >= '2010-01-01'
 GROUP BY 1
 ORDER BY 1
