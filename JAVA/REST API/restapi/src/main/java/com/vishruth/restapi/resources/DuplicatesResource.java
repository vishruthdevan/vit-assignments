/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/WebServices/GenericResource.java to edit this template
 */
package com.vishruth.restapi.resources;

import javax.ws.rs.core.Context;
import javax.ws.rs.core.UriInfo;
import javax.ws.rs.Consumes;
import javax.ws.rs.Produces;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PUT;
import javax.enterprise.context.RequestScoped;

/**
 * REST Web Service
 *
 * @author vishr
 */
@Path("duplicates")
@RequestScoped
public class DuplicatesResource {

    @Context
    private UriInfo context;

    /**
     * Creates a new instance of DuplicatesResource
     */
    public DuplicatesResource() {
    }

    /**
     * Retrieves representation of an instance of com.vishruth.restapi.resources.DuplicatesResource
     * @return an instance of java.lang.String
     */
    @GET
    @Produces(javax.ws.rs.core.MediaType.TEXT_HTML)
    public String getHtml() {
        return "<html><body>Bruh</body></html>";
        //TODO return proper representation object
        //throw new UnsupportedOperationException();
    }

    /**
     * PUT method for updating or creating an instance of DuplicatesResource
     * @param content representation for the resource
     */
    @PUT
    @Consumes(javax.ws.rs.core.MediaType.TEXT_HTML)
    public void putHtml(String content) {
    }
}
