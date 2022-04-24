class UndergroundSystem:

    def __init__(self):
        self.info = dict()
        self.record = dict()

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.info[id]=[stationName, t]

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        info = self.info[id]
        key = info[0]+'.'+stationName
        record = self.record.get(key, None)
        if record is None:
            record = self.record[key] = [0, 0]
        record[0] += t - info[1]
        record[1] += 1

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        key = startStation + '.' + endStation
        record = self.record.get(key, None)
        return record[0]/record[1]


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)