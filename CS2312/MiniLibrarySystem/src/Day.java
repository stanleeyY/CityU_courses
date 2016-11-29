import java.io.*;
import java.util.Scanner;

public class Day implements Cloneable, Comparable<Day> {

    private int year;
    private int month;
    private int day;
    private static final String MonthNames = "JanFebMarAprMayJunJulAugSepOctNovDec";

    //Constructor
    public Day(int y, int m, int d) {
        this.year = y;
        this.month = m;
        this.day = d;
    }

    public Day(String sDay) {
        set(sDay);
    }

    public void set(String sDay) {
        String[] sDayParts = sDay.split("-");
        this.year = Integer.parseInt(sDayParts[2]);
        this.day = Integer.parseInt(sDayParts[0]);
        this.month = MonthNames.indexOf(sDayParts[1]) / 3 + 1;
    }

    // check if a given year is a leap year
    static public boolean isLeapYear(int y) {
        if (y % 400 == 0)
            return true;
        else if (y % 100 == 0)
            return false;
        else if (y % 4 == 0)
            return true;
        else
            return false;
    }

    // check if y,m,d valid
    static public boolean valid(int y, int m, int d) {
        if (m < 1 || m > 12 || d < 1) return false;
        switch (m) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return d <= 31;
            case 4:
            case 6:
            case 9:
            case 11:
                return d <= 30;
            case 2:
                if (isLeapYear(y))
                    return d <= 29;
                else
                    return d <= 28;
        }
        return false;
    }

    // Return a string for the day like dd MMM yyyy
    @Override
    public String toString() {
        return day + "-" + MonthNames.substring((month - 1) * 3, month * 3) + "-" + year;
    }

    @Override
    public Day clone() {
        Day copy = null;
        try {
            copy = (Day) super.clone();
        } catch (CloneNotSupportedException e) {
            //GIVEN: Auto0generated catch block
            e.printStackTrace();
        }
        return copy;
    }

    public Day getNextDay() {
        if (valid(this.year, this.month, this.day + 1))
            return new Day(this.year, this.month, this.day + 1);
        else if (valid(this.year, this.month + 1, 1))
            return new Day(this.year, this.month + 1, 1);
        return new Day(this.year + 1, 1, 1);
    }

    @Override
    public int compareTo(Day another) {
        if (this.year == another.year && this.month == another.month && this.day == another.day)
            return 0;
        if (this.year > another.year)
            return 1;
        if (this.year < another.year)
            return -1;
        if (this.month > another.month)
            return 1;
        if (this.month < another.month)
            return -1;
        if (this.day > another.day)
            return 1;
        return -1;
    }
}