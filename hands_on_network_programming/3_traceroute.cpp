/* Although this is not cpp executable, the idea is worth sharing */

/* There are billions of routers with ip */

/* when we try to reach dns, it asks for AAAA-type or A-type record */

/* Once you receive you can connect to that server */

/* There are billion routers to choose from how do request/response work so wonderfully? */

/* How do we know which routes were taken for us to reach the destination server? */

/* one way to find out is using traceroute */

/*
 Traceroute tells us which ip it walked through
 */

/* ANOTHER IMPORTANT INFO */
/*
 * The devices on the same LAN
 * can directly address one another by their local address.
 * However, any traffic communicated to the internet must undergo address translation by the router.
 * The router does this by modifying the source IP address from the original private LAN IP address to its public internet IP address.
 * this address translation is done by NAT (network address translation)
 */