interface IoTData {
  deviceId: string;
  temperature: number;
  humidity: number;
  timestamp: Date;
}

interface AnalyticsResult {
  averageTemperature: number;
  averageHumidity: number;
}

function processDataAndCalculateAnalytics(data: IoTData[]): AnalyticsResult {
  // Calculate average temperature and humidity
  const totalTemperature = data.reduce((sum, d) => sum + d.temperature, 0);
  const totalHumidity = data.reduce((sum, d) => sum + d.humidity, 0);

  const averageTemperature = totalTemperature / data.length;
  const averageHumidity = totalHumidity / data.length;

  return {
    averageTemperature,
    averageHumidity,
  };
}

// Sample IoT data
const iotData: IoTData[] = [
  { deviceId: 'device1', temperature: 25.5, humidity: 60, timestamp: new Date() },
  { deviceId: 'device2', temperature: 22.3, humidity: 55, timestamp: new Date() },
  // ... more data
];

// Process data and calculate analytics
const analyticsResult = processDataAndCalculateAnalytics(iotData);

// Print the analytics result
console.log('Analytics Result:', analyticsResult);
