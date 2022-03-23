startYear = 1901
endYear = 2000

counter = 0
weekday = 1

for year in range(startYear, endYear+1):    
    for month in range(1, 13):
        if month == 2:
            if year % 4 == 0: days = 29
            else: days = 28
        elif month <= 7:
            if month % 2 == 0: days = 30
            else: days = 31
        else:
            if month % 2 == 0: days = 31
            else: days = 30
        
        for day in range(1, days+1):
            if day == 1 and weekday % 7 == 6: counter+=1

            weekday+=1

print("Anzahl an Sonntagen am Monatsbeginn: " + str(counter))