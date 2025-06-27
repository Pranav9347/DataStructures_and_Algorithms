def StringChallenge(strParam):
  start_time, end_time = strParam.split("-")
  def to_absolute_minutes(time):
    mins = 0
    period = time[-2:]
    hr_min = time[:-2]
    hr = int(hr_min.split(':')[0])
    minu = int(hr_min.split(':')[1])
    if period == "pm":
      mins = ((hr%12)*60 + minu) + 12*60
    else:
      mins = ((hr%12)*60 + minu)
    return mins
  st_min = to_absolute_minutes(start_time)
  en_min = to_absolute_minutes(end_time)
  diff = en_min-st_min
  while diff < 0:
    diff += 24*60
  return diff

# keep this function call here 
print(StringChallenge(input()))