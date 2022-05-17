# Hotel-Reservation-System
Development of an integrated hotel's room reservation system, which manages available booking dates and rooms (according to the tourist season, amount of booking days etc.)

The project consists of .cpp and .h files for classes: Hotel, Room, Reservation, RoomTypeA, RoomTypeB, RoomTypeC, RoomTypeD, RoomTypeE in which various functions have been implemented. 

As far as Main is concerned, 12 rooms are created, 2 of each type. A simple iteration structure is then created to simulate the booking system. In each iteration: Α reservation is initially created randomly and is called the HotelAddReservation() function of Hotel class. Then there is a 25% chance that a booking cancellation will occur. If it arises cancellation, one of the reservations from hotel's reservation list is randomly selected and the corresponding hotel cancellation method is called. Finally, a menu of options is displayed to the user with the following options:
1) Next Iteration
2) Add Reservation
3) Cancel Reservation
4) Show Reservations
5) Show Rooms
6) Βooking Plan View
7) Revenue Projection
8) Exit 
