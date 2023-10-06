---------------------------------------------------------
You'll need to add the sdl2 crate to your Cargo.toml file.
[dependencies]
sdl2 = "0.34.3"
-----------------------------------------------------------
Rust code-- 
  
extern crate sdl2;

use sdl2::event::Event;
use sdl2::keyboard::Keycode;
use sdl2::pixels::Color;
use sdl2::rect::{Point, Rect};
use sdl2::render::Canvas;
use sdl2::video::Window;
use sdl2::Sdl;
use std::time::Duration;

const WINDOW_WIDTH: u32 = 800;
const WINDOW_HEIGHT: u32 = 600;
const BALL_RADIUS: i32 = 20;
const BALL_COUNT: usize = 5;

struct Ball {
    position: Point,
    velocity: Point,
}

impl Ball {
    fn new(x: i32, y: i32, vx: i32, vy: i32) -> Self {
        Ball {
            position: Point::new(x, y),
            velocity: Point::new(vx, vy),
        }
    }

    fn update(&mut self) {
        self.position.x += self.velocity.x;
        self.position.y += self.velocity.y;

        // Bounce off walls
        if self.position.x < 0 || self.position.x > (WINDOW_WIDTH as i32 - BALL_RADIUS) {
            self.velocity.x = -self.velocity.x;
        }
        if self.position.y < 0 || self.position.y > (WINDOW_HEIGHT as i32 - BALL_RADIUS) {
            self.velocity.y = -self.velocity.y;
        }
    }
}

fn main() {
    let sdl_context = sdl2::init().unwrap();
    let video_subsystem = sdl_context.video().unwrap();
    let _sdl_timer = sdl_context.timer().unwrap();

    let window = video_subsystem
        .window("Bouncing Balls", WINDOW_WIDTH, WINDOW_HEIGHT)
        .position_centered()
        .build()
        .unwrap();

    let mut canvas = window.into_canvas().present_vsync().build().unwrap();

    let mut balls: Vec<Ball> = Vec::new();

    for _ in 0..BALL_COUNT {
        let x = rand::random::<i32>() % (WINDOW_WIDTH as i32 - BALL_RADIUS);
        let y = rand::random::<i32>() % (WINDOW_HEIGHT as i32 - BALL_RADIUS);
        let vx = rand::random::<i32>() % 5 + 1;
        let vy = rand::random::<i32>() % 5 + 1;

        balls.push(Ball::new(x, y, vx, vy));
    }

    let mut event_pump = sdl_context.event_pump().unwrap();

    'running: loop {
        for event in event_pump.poll_iter() {
            match event {
                Event::Quit { .. }
                | Event::KeyDown {
                    keycode: Some(Keycode::Escape),
                    ..
                } => break 'running,
                _ => {}
            }
        }

        for ball in &mut balls {
            ball.update();
        }

        canvas.set_draw_color(Color::RGB(0, 0, 0));
        canvas.clear();

        canvas.set_draw_color(Color::RGB(255, 255, 255));
        for ball in &balls {
            canvas
                .fill_rect(Rect::new(
                    ball.position.x,
                    ball.position.y,
                    BALL_RADIUS as u32,
                    BALL_RADIUS as u32,
                ))
                .unwrap();
        }

        canvas.present();

        ::std::thread::sleep(Duration::new(0, 1_000_000_000u32 / 60));
    }
}

