OBJ =  main.o Student.o Course.o Storage.o Control.o View.o CourseList.o FWMonitor.o GPAMonitor.o Monitor.o 

a4:	 StuServer.o $(OBJ)
	g++ -o a4 StuServer.o $(OBJ)

main.o:	main.cc Student.h Storage.h defs.h
		g++ -c main.cc

Student.o:	Student.cc Student.h Course.h Storage.h defs.h
	g++ -c Student.cc

Course.o:	Course.cc Course.h
	g++ -c Course.cc

Storage.o: Storage.cc Storage.h
	g++ -c Storage.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc

View.o: View.cc View.h
	g++ -c View.cc

CourseList.o: CourseList.cc CourseList.h
	g++ -c CourseList.cc

Monitor.o: Monitor.cc Monitor.h
	g++ -c Monitor.cc

GPAMonitor.o: GPAMonitor.cc GPAMonitor.h Monitor.h
	g++ -c GPAMonitor.cc

FWMonitor.o: FWMonitor.cc FWMonitor.h Monitor.h
	g++ -c FWMonitor.cc


clean:
	rm -f $(OBJ) a4
