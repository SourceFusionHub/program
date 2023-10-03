use actix_web::{get, web, App, HttpResponse, HttpServer, Responder};

// Define a handler function for the dynamic content
#[get("/{name}")]
async fn hello_path(info: web::Path<(String,)>) -> impl Responder {
    let name = &info.0;
    format!("Hello, {}!", name)
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    // Start the Actix HTTP server
    HttpServer::new(|| {
        App::new().service(hello_path)
    })
    .bind("127.0.0.1:8080")?
    .run()
    .await
}
