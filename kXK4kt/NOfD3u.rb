require 'gnuplot'

# Sample traffic flow data (replace with your own data)
timestamps = [1, 2, 3, 4, 5]
traffic_counts = [100, 120, 90, 110, 130]

# Create a line plot
Gnuplot.open do |gp|
  Gnuplot::Plot.new(gp) do |plot|
    plot.title 'Traffic Flow Analysis'
    plot.xlabel 'Time'
    plot.ylabel 'Traffic Count'

    x = timestamps
    y = traffic_counts

    plot.data << Gnuplot::DataSet.new([x, y]) do |ds|
      ds.with = 'linespoints'
      ds.title = 'Traffic Count'
    end
  end
end
