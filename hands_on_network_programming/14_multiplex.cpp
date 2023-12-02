/**
 * socket APIs are blocking by default
 * accept() blocks program until a new incoming connection is actually available.
 * recv() blocks program until new data is actually available.
 *
 * imagine that a server needed to serve multiple client.
 * then imagine that one slow client connected to it.
 *
 * the slow client takes a munute before sending its first data.
 *
 * During this time, our server would simply be waiting on the recv() call to return.
 *
 * If other clients were trying to connect, they would have to wait it out.
 */

/* Tomorrow goal : write multiplex using fork and select */