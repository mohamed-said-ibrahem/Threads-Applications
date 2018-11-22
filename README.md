# Threads-Applications:

1- Matrix Multiplication Using Threads (For each Row method) and (For each Element method).
2- BATMAN Using Threads, Monitors, Synchronization and Mutual exclusion.


# BATMAN:

Problem Statement:

A company has employed a Bidirectional Autonomous Trolley (BAT) system to move products from its
warehouses to the delivery trucks. Each BAT is a mobile platform that travels on separate tracks back
and forth between a warehouse and a truck. At most one BAT can cross at a time. Traffic at the
crossing arriving from the right has the right of way (i.e. East waits till North passes. North waits till
West passes and so on):

<p align="center"><img align="center" src ="https://github.com/mohamed-said-ibrahem/Threads-Applications/blob/master/BATMAN/image.png" /></p>


In our system each BAT is controlled by a separate thread. It is your task to create BATMAN: a BAT
Manager that prevents deadlock at a crossing. Part of the solution is to use one mutex lock for the
crossing, so that at most one BAT at a time can pass. The mutex lock will act as a monitor for the
BAT operations at the crossing. Besides the mutex lock, we will also need a set of condition variables
to control the synchronization of the BATs.

1. We need a condition variable per BAT to queue BATs arriving from one direction
(NorthQueue, EastQueue, SouthQueue, WestQueue). For example, when a BAT from North is
already at the crossing, a second BAT from North will have to wait.
2. Another type of condition variable is needed to let BATs from the right have precedence to cross
(NorthFirst, EastFirst, SouthFirst, WestFirst). However, using this rule can cause starvation. To
prevent starvation, when a BAT is waiting to cross but BATs continuously arriving from the right
have the right of way, we will let a BAT that just passed the crossing signal a waiting BAT on
his left.

When deadlock occurs the BAT Manager must signal one of the BATs to proceed, e.g. the BAT from
North. You will need a counter for each direction to keep track of the number of BATs waiting in line.
